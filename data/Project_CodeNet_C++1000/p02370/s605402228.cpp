#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V_MAX 10000
#define WHITE 1
#define BLACK 2

vector<int> G[V_MAX];
int indig[V_MAX];
int V_color[V_MAX];

vector<int> l;

void init(){
    for(int i = 0; i < V_MAX; i++){
        indig[i] = 0;
        V_color[i] = WHITE;
    }
}

void tpsort(int num){
    queue<int> Q;
    Q.push(num);
    int target;

    while(!Q.empty()){
        target = Q.front(); Q.pop();
        V_color[target] = BLACK;
        l.push_back(target);
        for(int i = 0; i < G[target].size(); i++){
            indig[G[target][i]]--;
            if(indig[G[target][i]] == 0){
                Q.push(G[target][i]);
            }
        }
    }
}

int main(void){
    init();
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i = 0; i < E; i++){
        int s, t, d;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        indig[t]++;
    }

    for(int i = 0; i < V; i++){
        if(indig[i] == 0 && V_color[i] == WHITE){
            tpsort(i);
        }
    }

    for(int i = 0; i < l.size(); i++){
        printf("%d\n", l[i]);
    }

    return 0;
}

