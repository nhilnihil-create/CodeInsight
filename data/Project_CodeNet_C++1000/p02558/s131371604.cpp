#include <bits/stdc++.h>
 
using namespace std;

struct DSU {
    int n;
    vector<int> p, sz;

    DSU(int n) : n(n) {
        p.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int x) {
        if (x == p[x]) return x;
        return p[x] = find_set(p[x]);
    }

    void union_set(int x, int y) {
        x = find_set(x); y = find_set(y);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            sz[x] += sz[y];
            p[y] = x;
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) dsu.union_set(u, v);
        else cout << (dsu.find_set(u) == dsu.find_set(v)) << '\n';
    }
}