#include <algorithm>
#include <cstdio>
#define MAX_E 100000

using namespace std;

struct edge {
    int u, v, cost;
    edge() {}
    edge(int a, int b, int c) : u(a), v(b), cost(c) {}
};

int n, m;
int par[MAX_E];
int rank[MAX_E];
edge edges[MAX_E];

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

// Ant book p84. union-find tree
void uf_init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int uf_find(int x) {
    if (par[x] == x) {
        return x;
    }
    else {
        return par[x] = uf_find(par[x]);
    }
}

void uf_unite(int x, int y) {
    x = uf_find(x);
    y = uf_find(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

bool uf_same(int x, int y) {
    return uf_find(x) == uf_find(y);
}

// Ant book p101. kruskal
int kruskal() {
    sort(edges, edges + m, comp);
    uf_init(n);
    int res = 0;
    for (int i = 0; i < m; i++) {
        edge e = edges[i];
        if (!uf_same(e.u, e.v)) {
            uf_unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    int x, y, w;

    scanf("%d %d", &n, &m);
    for (int j = 0; j < m; j++) {
        scanf("%d %d %d", &x, &y, &w);
        edges[j] = edge(x, y, w);
    }
    printf("%d\n", kruskal());

    return 0;
}