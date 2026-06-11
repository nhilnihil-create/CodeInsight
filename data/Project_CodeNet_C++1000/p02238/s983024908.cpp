#include <iostream>
#include <stack>

using namespace std;

#define MAX 110
int num;
int matrix[MAX][MAX];
int dst[MAX];
int counter = 0;
int D[MAX];
int F[MAX];

void input(){
    cin >> num;
    for(int i=0;i<MAX;i++){
        dst[i] = -1;
        for(int j=0;j<MAX;j++){
            matrix[i][j] = 0;
        }
    }
    for(int i=1;i<=num;i++){
        int v; cin >> v;
        int tmp; cin >>tmp;
        for(int j=0;j<tmp;j++){
            int vi; cin >> vi;
            matrix[v-1][vi-1] = 1;
        }
    }
}

void dfs(int cur){
    counter++;
    D[cur] = counter;
    for(int i=0; i< num;i++){
        if(matrix[cur][i] == 1 && D[i]== 0)
            dfs(i);
    }
    counter++;
    F[cur] = counter;
    return;
}

int check(){
    for(int i=0;i<num;i++){
        if(D[i]==0)
            return i;
    }
    return -1;
}

int main(){
    input();
    for(int i=0;i<MAX;i++){
        D[i] = 0;
        F[i] = 0;
    }
    dfs(0);
    while(check()!=-1){
        int a = check();
        dfs(a);
    }
    for(int i=0;i<num;i++){
        cout << i+1 << " " << D[i] << " " << F[i] << endl;
    }
}