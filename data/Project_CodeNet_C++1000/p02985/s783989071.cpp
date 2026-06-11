#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e+9 + 7;

using Graph = vector<vector<int64_t>> ;
Graph G;

int64_t N,K,num;

int64_t P(int64_t x, int64_t y){
    int64_t ans = 1;
    for ( int64_t i = 0; i < y; ++i){
        ans = ( ans * (x-i) ) % MOD;
    }
    return ans;
}

// 現在地v 親p
void dfs( int64_t v, int64_t p ) {
    if ( G[v].size() == 1 ){
        return;
    } else {
        num = ( num * P(K-2,(G[v].size()-1)) ) % MOD;
    }
    for ( int64_t nv: G[v] ){
        if ( nv == p ) continue;
        dfs(nv,v);
    }
    return;
}



int main() {
    cin >> N >> K;
    G.assign(N,vector<int64_t>());
    for ( int i = 0; i < N-1; ++i){
        int64_t a,b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //cout << "A" << endl;
    num = ( K * P(K-1,G[0].size()) ) % MOD;
    //cout << "A" << endl;
    for ( int64_t v: G[0]) {
        //cout << num << endl;
        dfs(v,0);
    }
    
    cout << num << endl;
    
    
    
    return 0;
}
