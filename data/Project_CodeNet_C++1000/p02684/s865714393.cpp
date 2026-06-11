#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    ll n, k; cin >> n >> k;
    vi a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    vector <bool> vis(n + 1);
    vi og;
    int u = 1, sz = 0;
    while (!vis[a[u]]) {
        og.pb(u);
        vis[u] = 1, u = a[u];
    }
    og.pb(u);
    vector <int> p;
    int v = a[u];
    while (1) {
        if (v == u) break;
        p.pb(v);
        v = a[v];
    }
    p.pb(u);
    if (k < og.size())
        cout << og[k] << endl;
    else {
        k -= og.size() - p.size();
        cout << p[k % p.size()] << endl;
    }
}