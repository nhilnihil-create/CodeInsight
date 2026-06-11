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
    
    vector<vector<P>> G(n);  // 辺の重みがすべて0以上のグラフ
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(make_pair(b, 1));
    }

    ll sv, gv;
    cin >> sv >> gv;
    sv--;  gv--;
    
    // 拡張ダイクストラ法。計算量はO((V+E)*log(V))
    vvl dp(n, vl(3, INF));  // dp[v][i] : 頂点vまでの3で割った余りがiとなる時間の最小値
    dp[sv][0] = 0;
    priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> prQ;
    prQ.push(make_pair(dp[sv][0], make_pair(sv, 0)));  // (頂点vまでの余りがiのときの時間t, (いまいる頂点v, 余りi))
    while(!prQ.empty()) {
        auto p1 = prQ.top();
        prQ.pop();
        ll t = p1.first;  //頂点vまでの余りがiのときの時間t
        ll v = p1.second.first;  // いまいる頂点v
        ll i = p1.second.second;  // 所持金i
        if(dp[v][i] < t) {
            continue;
        }
        for(auto p2 : G[v]) {
            ll u = p2.first;
            ll cost = p2.second;
            ll ni = (i + cost)%3;
            if(dp[u][ni] > dp[v][i] + cost) {
                dp[u][ni] = dp[v][i] + cost;
                prQ.push(make_pair(dp[u][ni], make_pair(u, ni)));
            }
        }
    }
    
    if(dp[gv][0] == INF) {
        out(-1);
    }
    else {
        out(dp[gv][0]/3);
    }
    
    re0;
}