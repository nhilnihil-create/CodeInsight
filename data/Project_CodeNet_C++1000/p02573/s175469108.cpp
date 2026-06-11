#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define len(a) (int)a.size()
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

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
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
    }
    int ans = 0;
    rep(i, n) {
        ans = max(ans, uf.size(i));
    }
    cout << ans << endl;
}
