#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

struct UnionFind {
    UnionFind(int n) : p(n, -1) {}
    int root(int u) {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
    int size(int u) {
        return -p[root(u)];
    }
    bool same(int u, int v) {
        return root(u) == root(v);
    }
    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
    vector<int> p;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            uf.unite(u, v);
        } else {
            cout << uf.same(u, v) << '\n';
        }
    }

    return 0;
}