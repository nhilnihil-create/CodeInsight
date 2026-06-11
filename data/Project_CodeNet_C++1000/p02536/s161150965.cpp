#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct disj {
    int par[N], sz[N], ncc;
    void init (int n) {
        iota(par + 1, par + n + 1, 1);
        fill(sz + 1, sz + n + 1, 1);
        ncc = n;
    }

    int Find (int x) {
        return par[x] == x ? x : par[x] = Find(par[x]);
    }

    void join (int x, int y) {
        x = Find(x); y = Find(y);
        if (x == y) return;
        ncc--;

        if (sz[x] > sz[y]) {
            sz[x] += sz[y];
            par[y] = x;
        } else {
            sz[y] += sz[x];
            par[x] = y;
        }
    }
} dsu;

int n, m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m; dsu.init(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.join(u, v);
    }

    cout << dsu.ncc - 1 << "\n";
    return 0;
}
