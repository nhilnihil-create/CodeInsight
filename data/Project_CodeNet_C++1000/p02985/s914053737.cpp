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

ll Perm(ll x, ll y) {
    if(x < y || x < 0 || y < 0) {
        return 0;
    }
    ll res = 1;
    rep(i, y) {
        res *= x;
        res %= mod;
        x--;
    }
    return res;
}

vvl G;
ll n, k;
ll ans;

void dfs(ll v, ll p = -1) {
    // 行きの処理はこのへんに書く
    if(p == -1) {  // 根の場合
        ans *= Perm(k-1, G[v].size());  // 根の色以外のk-1色から、根の子の数だけ選んで並べる順列数通り塗り方がある
    }
    else {  // 根以外の場合
        ans *= Perm(k-2, G[v].size()-1);  // 親と、親の親以外の色のk-2色から「親の子の数」だけ選んで並べる順列数通り塗り方がある
    }
    ans %= mod;
    for(auto u : G[v]) {
        if(u == p) {
            continue;
        }
        dfs(u, v);
        // 帰りの処理はこのへんに書く
    }
}

int main() {
    
    cin >> n >> k;    

    G.resize(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    ans = k;  // 根はk色から好きな色で塗れる
    const ll root = 0;
    dfs(root);

    out(ans);
    re0;
}