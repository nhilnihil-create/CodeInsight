#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const int N = 10000;
const int WHITE = 0;
const int  GRAY = 1;
const int BLACK = 2;

vector<int> G[N];
vector<int> ans;
int V;
int degIn[N], color[N];

queue<int> Q;

void bfs(int s){
    if( degIn[s] > 0 || color[s] == BLACK) return;

    Q.push(s);

    int u;
    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        ans.push_back(u);
        color[u] = BLACK;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            degIn[v]--;
            if(degIn[v] == 0 && color[v] != BLACK){
                Q.push(v);
            }
        } 
    }

}

void solve(){
    rep(i,V) bfs(i);

    rep(i,V) printf("%d\n", ans[i]);
}


int main(){
    int E;
    cin >> V >> E;

    rep(i,V){
        color[i] = WHITE;
        degIn[i] = 0;
    }

    int s, t;
    rep(i,E){
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        degIn[t]++;
    }

    solve();

    return 0;

}
