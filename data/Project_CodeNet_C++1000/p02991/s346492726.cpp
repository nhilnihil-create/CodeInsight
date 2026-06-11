#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, start, stop, ans=0, tmp=0;
vector<vector<ll>> G;

void bfs(){
    ll DP[N][3];
    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            DP[i][j] = INF;
        }
    }
    queue<pair<ll,ll>> Q;
    Q.push(make_pair(start,0));
    DP[start][0]=0;
    while(!Q.empty()) {
        pair<ll,ll> p = Q.front();
        Q.pop();
        for(int i=0;i<G[p.first].size();i++) {
            if(DP[G[p.first][i]][(p.second+1)%3]!=INF) continue;
            else {
                DP[G[p.first][i]][(p.second+1)%3] = p.second+1;
                Q.push(make_pair(G[p.first][i], p.second+1));
            }
        }
    }
    if(DP[stop][0]==INF) ans = -1;
    else ans = DP[stop][0]/3;
}

signed main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<M;i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }
    cin >> start >> stop;
    start--;
    stop--;
    bfs();
    cout << ans << endl;
    return 0;
}