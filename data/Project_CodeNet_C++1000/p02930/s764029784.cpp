#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll N;
int L[600][600];
int isvisit[600];
int rem;

void dfs(int v, int t, int level){
    isvisit[v] = t; 
    for(int i = 0; i < N; i++){
            if(L[v][i] != 0 || L[i][v]) continue;
            if(isvisit[i] == t) continue;
            L[v][i] = L[i][v] = level;
            rem--;
            if(isvisit[i] == 0)
                dfs(i, -t, level);
    }
}

int main(){
    cin >> N;

    rem = N*(N-1) / 2;

    int level = 1;
    while(rem > 0){
        fill(isvisit, isvisit+N, 0);
        for(int i = 0; i < N; i++){
            if(isvisit[i] == 0)
                dfs(i, 1, level);
        }
        level++;
    }

    //cout << level - 1<< endl;

    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }
    return 0;
}
