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
    ll to, id;
    Edge(ll to, ll id):to(to),id(id) {}
};

vector<vector<Edge>> G;
vl ans;
 
void dfs(ll v, ll p = -1, ll c = 0) {
    // 行きの処理はこのへんに書く
    ll num = 1;
    for(Edge e : G[v]) {
        if(e.to == p) {
            continue;
        }
        if(num == c) {
            num++;
        }
        ans[e.id] = num;
        num++;
        dfs(e.to, v, ans[e.id]);
        // 帰りの処理はこのへんに書く
    }
}
 
int main() {
    ll n;
    cin >> n;    
 
    G.resize(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    
    ll K = 0;
    rep(v, n) {
        chmax(K, (ll)G[v].size());
    }
    out(K);
    
    const ll root = 0;
    ans.resize(n-1);
    dfs(root);
    
    rep(id, n-1) {
        out(ans[id]);
    }
    
    re0;
}