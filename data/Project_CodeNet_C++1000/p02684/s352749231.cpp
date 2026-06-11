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
 
vvl G;
vl visited;
vl finished;
vl hist;
 
ll pos = -1;  // サイクルに含まれる頂点pos(-1のときサイクルを含まない)
 
void dfs(ll v) {
    visited[v] = 1;
    hist.pb(v);
    for(auto u : G[v]) {
        if(finished[u]) {
            continue;
        }
        // サイクルを検出
        if(visited[u] && !finished[u]) {
            pos = u;
            return;
        }
        dfs(u);
        if(pos != -1) {
            return;
        }
    }
    hist.pop_back();
    finished[v] = 1;
}
 
int main() {
    ll n, k;
    cin >> n >> k;    
    
    G.resize(n);
    rep(i, n) {
        ll a;
        cin >> a;
        a--;  
        G[i].pb(a);
    }
    
    visited.assign(n, 0);
    finished.assign(n, 0); 
    dfs(0);
    
    // サイクルを復元 
    vl cycle;
    while(!hist.empty()) {
        ll t = hist.back();
        cycle.pb(t);
        hist.pop_back();
        if(t == pos) {
            break;
        }
    }
    reverse(all(cycle));

    ll now = 0;
    ll x = 0;  // 頂点0からサイクルに到達するまでの長さ
    while(now != pos) {
        now = G[now][0];
        x++;
    }
    ll y = cycle.size();  // サイクルの長さ
    
    now = 0;
    if(x < k) {  // k回移動後サイクルに到達するとき
        k -= x;
        k %= y;
        now = pos;
    }
    
    rep(i, k) {
        now = G[now][0];
    }

    out(now+1);
    re0;
}