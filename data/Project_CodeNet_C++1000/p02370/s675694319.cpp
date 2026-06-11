//
//  main.cpp
//  topological_sort
//
//  Created by ???????????? on 2017/11/13.
//  Copyright ?? 2017 ????????????. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

static const int MAX = 100000;
static const int WHITE = 0;
static const int GRAY = 1;

vector<int> adjList[MAX];
vector<int> out;
int colors[MAX];
int indeg[MAX];
//int openTable


void bfs(int vertexInd, int numVertex){
    queue<int> Q;
    Q.push(vertexInd);
    colors[vertexInd] = GRAY;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        out.push_back(u);
        
        for(int i = 0; i < adjList[u].size(); i++ ){
            int adjInd = adjList[u][i];
            indeg[adjInd]--;
            if(indeg[adjInd] == 0 && colors[adjInd] == WHITE){
                colors[adjInd] = GRAY;
                Q.push(adjInd);
            }
        }
    }
}

void topologicalSort(int numVertex){
    
    //init
    for(int i = 0; i < numVertex; i++){
        colors[i] = WHITE;
        indeg[i] = 0;
    }
    
    for(int i = 0; i < numVertex; i++){
        for (int j = 0; j < adjList[i].size(); j++) {
            int temp = adjList[i][j];
            indeg[temp]++;
        }
    }
    
    
    for(int i = 0; i < numVertex; i++){
        if (indeg[i] == 0 && colors[i] == WHITE){
            bfs(i, numVertex);
        }
    }
}

int main(int argc, const char * argv[]) {
    int numVertex, numEdge;
    scanf("%d %d", &numVertex, &numEdge);
    
    int x, y;
    for (int i = 0; i < numEdge; i ++){
        scanf("%d %d", &x, &y);
        adjList[x].push_back(y);
    }
    
    topologicalSort(numVertex);
    
    //print "out"
    for(int i = 0; i < out.size(); i ++){
        cout << out[i] << endl;
    }
    
    
//    std::cout << "Hello, World!\n";
    return 0;
}