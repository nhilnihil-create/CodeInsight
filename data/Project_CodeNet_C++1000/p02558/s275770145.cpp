#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct DSU {
    int par[N], sz[N];
    void init (int n) {
        iota(par + 1, par + n + 1, 1);
        fill(sz + 1, sz + n + 1, 1);
    }

    int Find (int x) {
        return par[x] == x ? x : par[x] = Find(par[x]);
    }

    bool same (int x, int y) {
        return Find(x) == Find(y);
    }

    void join (int x, int y) {
        x = Find(x); y = Find(y);
        if (x == y) return;

        if (sz[x] > sz[y]) sz[x] += sz[y], par[y] = x;
        else sz[y] += sz[x], par[x] = y;
    }
} dsu;

int n, q, t, u, v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q; dsu.init(n);
    for (int i = 1; i <= q; i++) {
        cin >> t >> u >> v; u++; v++;
        if (t == 0) dsu.join(u, v);
        else cout << (dsu.same(u, v) ? 1 : 0) << "\n";
    }
    return 0;
}
