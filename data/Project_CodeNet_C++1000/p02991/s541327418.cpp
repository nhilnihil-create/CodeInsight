#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1000000000100000000;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m){
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
    }
    int s, t; cin >> s >> t; s--, t--;
    vector<vector<ll>> dist(n, vector<ll>(3, LINF));
    dist[s][0] = 0;
    queue<pii> que; que.push({s, 0});
    while(!que.empty()){
        auto p = que.front(); que.pop();
        int v = p.first, cost = p.second;
        int to = (cost + 1) % 3;
        for(auto e: G[v]){
            if(dist[e][to] != LINF)continue;
            dist[e][to] = dist[v][cost] + 1;
            que.push({e, to});
        }
    }
    ll res = dist[t][0];
    if(dist[t][0] == LINF) res = -1;
    else res /= 3;
    cout << res << ln;
}