#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "Yes" : "No")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 2e5 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "3";

int par[siz], len[siz];

void init() {
    for (int u = 0; u < siz; u++) {
        par[u] = u;
        len[u] = 1;
    }
}

int root(int u) {
    if (u == par[u]) {
        return u;
    }
    return (par[u] = root(par[u]));
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);

    if (u == v) {
        return;
    }

    if (len[u] < len[v]) {
        swap(u, v);
    }

    par[v] = u;
    len[u] += len[v];
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    init();

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;

        unite(u, v);
    }

    int ans = 0;
    for (int u = 1; u <= n; u++) {
        ans = max(ans, len[root(u)]);
    }

    cout << ans << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
