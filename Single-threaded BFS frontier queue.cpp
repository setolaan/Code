char* BFSTraverse(graph<long, long, int, long, long, char>* ginst,int source){
    int j,frontier =0; char* statusArray = new char[ginst->vert_count];
    for (int i = 0; i < ginst->vert_count; i++) 
        statusArray[i] = -1; //-1 means unvisited;

    int* currFrontierQueue = new int[ginst->vert_count];
    int* nextFrontierQueue = new int[ginst->vert_count];
    int currFrontierSize = 0;
    int nextFrontierSize = 0; currFrontierQueue[currFrontierSize] = source; currFrontierSize++; statusArray[source] = 0;
    int myFrontierIndex = 0;
    int currLevel = 1; 
    while (true){ 
        while (myFrontierIndex < currFrontierSize) {
            frontier = currFrontierQueue[myFrontierIndex];
            long int beg = ginst->beg_pos[frontier];
            long int end = ginst->beg_pos[frontier + 1];
            
            for (j = beg; j < end; j++) {
                if (statusArray[ginst->csr[j]] == -1) {
                    statusArray[ginst->csr[j]] = currLevel; 
                    nextFrontierQueue[nextFrontierSize] = ginst->csr[j]; 
                    nextFrontierSize++;
                }
            }
            myFrontierIndex++;
        }
        if (nextFrontierSize == 0) { 
            return statusArray;
        }
        //Swap current and next frontier queue; 
        currFrontierSize = nextFrontierSize; 
        myFrontierIndex = 0; 
        nextFrontierSize = 0;
        
        int* temp = currFrontierQueue; 
        currFrontierQueue = nextFrontierQueue; 
        nextFrontierQueue = temp; 
        currLevel++;
    }
}