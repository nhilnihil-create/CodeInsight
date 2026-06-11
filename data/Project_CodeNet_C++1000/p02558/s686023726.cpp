#include <bits/stdc++.h>
using namespace std;

// https://ei1333.github.io/library/library/structure/union-find/union-find.cpp.html
struct UnionFind {
    vector<int> data;

    UnionFind() = default;

    explicit UnionFind(size_t sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if (data[k] < 0) return (k);
        return data[k] = find(data[k]);
    }

    int size(int k) { return -data[find(k)]; }

    bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            uf.unite(u, v);
        else
            cout << int(uf.same(u, v)) << '\n';
    }
}