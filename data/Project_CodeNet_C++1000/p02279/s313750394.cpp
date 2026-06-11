#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

using Weight=int;
using DArray=vector<Weight>;
using DMatrix=vector<DArray>;

static const Weight INF=1<<29;

struct Edge {
    size_t src, dst;
    Weight weight;
    Edge() {}
    Edge(size_t src, size_t dst, Weight weight=1):
        src(src), dst(dst), weight(weight)
    {}
};


bool operator<(const Edge &e, const Edge &f) {
    if (e.weight != f.weight) {
        return e.weight > f.weight;
    } else {
        return e.src!=f.src? e.src<f.src : e.dst<f.dst;
    }
}

using Edges=vector<Edge>;
using Vertex=vector<Edge>;
using Graph=vector<Vertex>;

void join(Graph &g, size_t s, size_t d, Weight w=1) {
    // non-directed
    g[s].push_back(Edge(s, d, w));
    g[d].push_back(Edge(d, s, w));
}

void connect(Graph &g, size_t s, size_t d, Weight w=1) {
    // directed
    g[s].push_back(Edge(s, d, w));
}

int main() {
    size_t n;
    scanf("%zu", &n);

    Graph g(n);
    vector<size_t> parent(n, -1);
    for (size_t i=0; i<n; ++i) {
        size_t p, m;
        scanf("%zu %zu", &p, &m);
        for (size_t j=0; j<m; ++j) {
            size_t c;
            scanf("%zu", &c);
            connect(g, p, c);
            parent[c] = p;
        }
    }

    for (size_t i=0; i<n; ++i) {
        printf("node %zu: ", i);
        if (~parent[i]) {
            printf("parent = %zu, ", parent[i]);
        } else {
            printf("parent = -1, ");
        }

        size_t d=0;
        for (size_t j=i; ~parent[j]; j=parent[j])
            ++d;

        printf("depth = %zu, ", d);
        if (!d) {
            printf("root, ");
        } else if (g[i].empty()) {
            printf("leaf, []\n");
            continue;
        } else {
            printf("internal node, ");
        }

        printf("[");
        if (g[i].empty()) {
            printf("]\n");
            continue;
        }

        for (size_t j=0; j<g[i].size(); ++j)
            printf("%zu%s", g[i][j].dst, j<g[i].size()-1? ", ":"]\n");
    }

    return 0;
}