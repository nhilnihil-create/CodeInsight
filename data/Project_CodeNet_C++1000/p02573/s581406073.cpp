#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> tree;

    UnionFind(int n) : tree(n, -1) {}

    int root(int n) {
        if (tree[n] < 0) return n;
        return tree[n] = root(tree[n]);
    }

    void unite(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (tree[a] > tree[b]) swap(a, b);
        tree[a] += tree[b];
        tree[b] = a;
    }

    int size(int n) { return -tree[root(n)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (size_t i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, uf.size(i));
    }
    cout << res << endl;
}
