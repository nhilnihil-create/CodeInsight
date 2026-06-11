#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n, num;
    vector<int> sz, parent;
    UnionFind() {}
    UnionFind(int n_) : n(n_), num(n_), sz(n_, 1), parent(n_, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return x==parent[x] ? x : parent[x]=find(parent[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        parent[y] = x;
        num--;
    }
    int size(int x) { return sz[find(x)]; }
    int count() const { return num; }
};

int main() {
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    for ( int i=0; i<m; i++ ) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        uf.unite(a,b);
    }
    cout << uf.num - 1 << '\n';
    return 0;
}