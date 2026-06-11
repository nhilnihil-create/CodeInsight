#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
    vector<int> d;
    UnionFind(int n): d(n,-1) {}
    int root(int x) {
        if (d[x] < 0) return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y);}
    int size(int x) { return -d[root(x)];}
};  // UnionFind uf(N+1);  // 1-indexed

int deg[200005];
vector<int> graph[200005];

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N+1);
    rep(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            if (uf.same(u, v)) cout << '1' << '\n';
            else cout << '0' << '\n';
        }
    }
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}