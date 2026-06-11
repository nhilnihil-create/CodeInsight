#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

template <class T>
using lp_queue=priority_queue<T, deque<T>, greater<T>>;

using Weight=long long;
static const Weight INF=1LL<<57;

template <class Weight>
struct Edge {
    size_t src, dst;
    Weight weight;
    Edge() {}
    Edge(size_t src, size_t dst, Weight weight=1):
        src(src), dst(dst), weight(weight)
    {}
};

template <class Weight>
bool operator<(const Edge<Weight> &e, const Edge<Weight> &f) {
    if (e.weight != f.weight) {
        return e.weight > f.weight;
    } else {
        return e.src!=f.src? (e.src < f.src) : (e.dst < f.dst);
    }
};

template <class Weight>
using Edges=vector<Edge<Weight>>;
template <class Weight>
using Vertex=vector<Edge<Weight>>;
template <class Weight>
using Graph=vector<Vertex<Weight>>;

template <class Weight>
void join(Graph<Weight> &g, size_t s, size_t d, Weight w=1) {
    g[s].push_back(Edge<Weight>(s, d, w));
    g[d].push_back(Edge<Weight>(d, s, w));
}

template <class Weight>
void connect(Graph<Weight> &g, size_t s, size_t d, Weight w=1) {
    g[s].push_back(Edge<Weight>(s, d, w));
}

template <class Weight>
vector<Weight> shortest_distance(const Graph<Weight> &g, size_t s) {
    /* Dijkstra */
    size_t V=g.size();
    vector<Weight> d(V, INF); d[s]=0;

    lp_queue<pair<Weight, size_t>> q; q.push(make_pair(0, s));
    while (!q.empty()) {
        pair<Weight, size_t> p=q.top(); q.pop();
        size_t v=p.second;
        if (d[v] < p.first) continue;

        for (const Edge<Weight> &e: g[v])
            if (d[e.dst] > d[v] + e.weight) {
                d[e.dst] = d[v] + e.weight;
                q.push(make_pair(d[e.dst], e.dst));
            }
    }
    return d;
}


int main() {
    size_t V, E, r;
    scanf("%zu %zu %zu", &V, &E, &r);

    Graph<Weight> g(V);
    for (size_t i=0; i<E; ++i) {
        size_t s, t;
        Weight d;
        scanf("%zu %zu %lld", &s, &t, &d);

        connect(g, s, t, d);
    }

    vector<Weight> d=shortest_distance(g, r);
    for (size_t i=0; i<V; ++i)
        if (d[i] < INF) {
            printf("%lld\n", d[i]);
        } else {
            printf("INF\n");
        }

    return 0;
}