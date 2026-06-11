#include <stdio.h>
#include <iostream>
using namespace std;

#define NIL -1
#define INF 100000000
#define WHITE 1
#define GREY 2
#define BLACK 3
#define N_MAX 100

int G[N_MAX][N_MAX];
int V[N_MAX];
int V_value[N_MAX];

void init(){
    for(int i = 0; i < N_MAX; i++){
        V[i] = WHITE;
        V_value[i] = INF;
    }

    for(int i = 0; i < N_MAX; i++){
        for(int j = 0; j < N_MAX; j++){
            G[i][j] = NIL;
        }
    }
}

int main(void){
    init();
    int n;
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        int u, k;
        scanf("%d %d", &u, &k);
        for(int j = 0; j < k; j++){
            int v, c;
            scanf("%d %d", &v, &c);
            G[u][v] = c;
        }
    }

    V[0] = BLACK;
    V_value[0] = 0;
    int new_node = 0;
    
    while(1){
        for(int i = 0; i < n; i++){
            if(G[new_node][i] != NIL && V[i] == WHITE){
                V_value[i] = min(V_value[i], V_value[new_node] + G[new_node][i]);
            }
        }

        int min_index = NIL;
        int min_value = INF;
        for(int i = 0; i < n; i++){
            if(V[i] == WHITE && V_value[i] < min_value){
                min_value = V_value[i];
                min_index = i;
            }
        }
        if(min_index == NIL){
            break;
        }else{
            new_node = min_index;
            V[new_node] = BLACK;
            V_value[new_node] = min_value;
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("%d %d\n", i, V_value[i]);
    }

    return 0;
}

