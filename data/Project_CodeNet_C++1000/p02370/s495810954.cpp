#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

template <class T>
using lp_queue=priority_queue<T, deque<T>, greater<T>>;

using Weight=long long;
static const Weight INF=1LL<<57;

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

vector<size_t> tsort(const Graph &g) {
    /* Kahn */
    // returns lexico-smallest one.
    // if impossible, returns empty vector.
    size_t V=g.size();
    vector<size_t> indeg(V);

    for (const Vertex &v: g)
        for (const Edge &e: v)
            ++indeg[e.dst];

    lp_queue<size_t> q;
    for (size_t i=0; i<V; i++)
        if (!indeg[i]) q.push(i);

    vector<size_t> ord(V);
    for (size_t k=0; !q.empty(); ++k) {
        int v=q.top(); q.pop();
        ord[k] = v;
        for (const Edge &e: g[v])
            if (!--indeg[e.dst]) q.push(e.dst);
    }
    return *max_element(indeg.begin(), indeg.end())? vector<size_t>():ord;
}

int main() {
    size_t V, E;
    scanf("%zu %zu", &V, &E);

    Graph g(V);
    for (size_t i=0; i<E; ++i) {
        size_t s, t;
        scanf("%zu %zu", &s, &t);

        connect(g, s, t);
    }

    vector<size_t> ord=tsort(g);

    for (size_t v: ord)
        printf("%zd\n", v);

    return 0;
}