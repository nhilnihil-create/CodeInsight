#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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
const double pi = acos(-1);

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost): to(to), cost(cost) {}
};

struct Data {
    ll v, i, x;  // いまいる頂点v, 進んだ距離を3で割った余りi, 進んだ距離x
    Data(ll v, ll i, ll x): v(v), i(i), x(x) {}
    bool operator<(const Data& hoge) const {
        return x > hoge.x;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;    
    
    vector<vector<Edge>> G(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].emplace_back(b, 1);
    }

    ll sv, gv;
    cin >> sv >> gv;
    sv--;  gv--;

    vvl dp(n, vl(3, INF));  // dp[v][i] : 頂点vまでの3で割った余りがiとなる距離の最小値
    priority_queue<Data> Q;
    auto push = [&](ll v, ll i, ll x) {
        if(dp[v][i] <= x) {
            return;
        }
        dp[v][i] = x;
        Q.emplace(v, i, x);
    };
    
    // 拡張ダイクストラ法。計算量はO((V+E)*log(V))
    push(sv, 0, 0);
    while(!Q.empty()) {
        Data hoge = Q.top();  Q.pop();
        ll v = hoge.v, i = hoge.i, x = hoge.x;
        if(dp[v][i] != x) {
            continue;
        }
        for(Edge e : G[v]) {
            push(e.to, (i + e.cost)%3, x + e.cost);
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