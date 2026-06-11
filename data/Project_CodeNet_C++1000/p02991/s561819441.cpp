#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>

std::vector<int > edge[300005];

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    int u, v;
    std::vector<int> dist(300005, -1);

    for (int i=0; i<M; i++){
        scanf("%d", &u);
        scanf("%d", &v);
        u--;
        v--;
        edge[u].push_back(v+N);
        edge[u+N].push_back(v+2*N);
        edge[u+2*N].push_back(v);
    }
    int S, T;
    scanf("%d", &S);
    scanf("%d", &T);
    S--;
    T--;
    dist[S]=0;
    std::queue<int> queue;
    queue.push(S);
    while(queue.size()>0){
        int v = queue.front();
        queue.pop();
        for (int vv : edge[v]){
            if (dist[vv]==-1){
                dist[vv]=dist[v]+1;
                queue.push(vv);
            }
        }
    }
    if (dist[T]!=-1) dist[T]=dist[T]/3;
    printf("%d\n", dist[T]);
}