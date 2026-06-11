#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n, m;
    cin >> n >> m;    
    
    vvl G(n);  // 辺の重みがすべて1のグラフ
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
    }

    ll sv, gv;
    cin >> sv >> gv;
    sv--;  gv--;
    
    // BFS。計算量はO(V+E)
    vvl dist(n, vl(3, -1));  // dist[v][x] : 頂点svから頂点vへの3で割った余りがxとなる最短距離(-1のとき未訪問)
    queue<P> Q;
    dist[sv][0] = 0;
    Q.push(make_pair(sv, 0));
    while(!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        ll v = p.first;
        ll x = p.second;
        for(auto u : G[v]) {
            if(dist[u][(x+1)%3] == -1) {
                dist[u][(x+1)%3] = dist[v][x] + 1;
                Q.push(make_pair(u, (x+1)%3));
            }
        }
    }

    if(dist[gv][0] == -1) {
        out(-1);
    }
    else {
        out(dist[gv][0]/3);
    }

    re0;
}