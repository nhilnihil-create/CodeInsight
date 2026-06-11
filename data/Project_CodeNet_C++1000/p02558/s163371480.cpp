#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
private:
    vector<int> par;
    vector<int> sizes;
public:
    UnionFind(int n): par(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) par[i] = i;
    }
    ~UnionFind() = default;
    int find(int x) {
        return x == par[x] ? x : find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return sizes[find(x)];
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        else if (t == 1) cout << uf.same(u, v) << endl;
    }
}
