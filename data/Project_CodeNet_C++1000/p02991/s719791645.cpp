#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
using pint = pair<int,int>;

int N,M;
Graph G;
int S,T;

int64_t solve(){
    vector<vector<int64_t>> dist(N,vector<int64_t>(3,-1));
    dist[S][0] = 0;
    queue<pint> que;
    que.push(pint(S,0));
    while ( !que.empty() ){
        pint p = que.front(); que.pop();
        int64_t pos = p.first;
        int64_t num = p.second;
        for ( auto npos: G[pos] ){
            int64_t nnum = ( num + 1 ) % 3;
            if ( dist.at(npos).at(nnum) == -1 ){
                dist.at(npos).at(nnum) = dist.at(pos).at(num) + 1;
                que.push(pint(npos,nnum));
            }
        }
    }
    if ( dist.at(T).at(0) == -1 ) return -1;
    else return dist.at(T).at(0) / 3 ;
}

int main() {
    cin >> N >> M;
    G.assign(N,vector<int>());
    for ( int i = 0; i < M; ++i){
        int u,v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
    }
    cin >> S >> T ;
    --S; --T;
    cout << solve() << endl;
    
    return 0;
}

