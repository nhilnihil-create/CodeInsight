#include <cstdio>
#include <vector>

using namespace std;

struct uf_find_tree {
    vector<int> par, sizes;
    uf_find_tree(int n) : par(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) { par[i] = i; }
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) { swap(x, y); }
        par[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return sizes[find(x)]; }
};

int main() {
    int n, m, s, t, q;

    scanf("%d %d", &n, &m);

    uf_find_tree uf(n);

    while (m--) {
        scanf("%d %d", &s, &t);
        uf.unite(s, t);
    }

    scanf("%d", &q);

    while (q--) {
        scanf("%d %d", &s, &t);
        printf((uf.same(s, t)) ? "yes\n" : "no\n");
    }

    return 0;
}
