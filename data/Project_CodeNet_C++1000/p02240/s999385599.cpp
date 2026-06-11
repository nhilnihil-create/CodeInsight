#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000
#define WHITE 1
#define GREY 2
#define BLACK 3

vector<int> G[MAX_N];
int V[MAX_N];
int V_num[MAX_N];

void init(void){
    for(int i = 0; i < MAX_N; i++){
        V[i] = WHITE;
        V_num[i] = i;
    }
}

void labeling(int target){
    queue<int> Q;
    Q.push(target);
    while(!Q.empty()){
        int num = Q.front(); Q.pop();
        for(int i = 0; i < G[num].size(); i++){
            if(V[G[num][i]] == WHITE){
                Q.push(G[num][i]);
                V[G[num][i]] = GREY;
                V_num[G[num][i]] = target;
            }
        }
        V[num] = BLACK;
    }
}

int main(void){
    init();
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(V[i] != WHITE){
            continue;
        }
        labeling(i);
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(V_num[a] == V_num[b]){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }

    /*
    for(int i = 0; i < n; i++){
        printf("%d %d\n", i, V_num[i]);
    }
    */
}

