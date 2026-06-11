#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
struct edge { int to, cost; };

struct UnionFind {
    vector<int> parent;
    UnionFind(int n) {
        parent.assign(n, -1);
    }
    int find(int x) {
        if (parent[x] < 0) return x;
        return (parent[x] = find(parent[x]));
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size(x) < size(y)) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
    }
    int size(int x) {
        return -parent[find(x)];
    }
};


int main() {
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    rep(loop, q) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            cout << (uf.same(u, v) ? 1 : 0) << endl;
        } else {
            uf.unite(u, v);
        }
    }
}
