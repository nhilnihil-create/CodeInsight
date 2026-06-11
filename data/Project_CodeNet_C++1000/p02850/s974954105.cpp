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

vector<vector<P>> G;
vl ans;

void dfs(ll v, ll p = -1, ll c = 0) {
    // 行きの処理はこのへんに書く
    ll num = 1;
    for(auto z : G[v]) {
        ll u = z.first;
        ll id = z.second;
        if(u == p) {
            continue;
        }
        if(num == c) {
            num++;
        }
        ans[id] = num;
        num++;
        dfs(u, v, ans[id]);
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
        G[a].pb(make_pair(b, i));
        G[b].pb(make_pair(a, i));
    }

    ll K = 0;
    rep(v, n) {
        chmax(K, (ll)G[v].size());
    }
    out(K);

    const ll root = 0;
    ans.resize(n-1);
    dfs(root);

    rep(v, n-1) {
        out(ans[v]);
    }

    re0;
}