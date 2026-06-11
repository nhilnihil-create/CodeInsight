#include <iostream>
#include <queue>
#include <vector>

struct edge {
    typedef size_t weight_type;

    size_t m_to;

    edge(size_t to) : m_to(to) { }

    inline size_t to() const { return m_to; }

    inline weight_type weight() const { return 1; }

    friend std::ostream& operator<<(std::ostream &os, const edge &e) {
        os << "{ to: " << e.m_to << " }";
        return os;
    }
};

template <class Edge>
struct graph {
    typedef Edge edge_type;

    size_t m_n_vertices;
    std::vector<std::vector<edge_type>> m_edges;

    graph(size_t n_vertices) : m_n_vertices(n_vertices), m_edges(n_vertices) { }

    inline size_t n_vertices() const { return m_n_vertices; }

    inline void make_edge(size_t from, size_t to, typename edge_type::weight_type weight) {
        m_edges[from].emplace_back(edge_type(to, weight));
    }

    inline void make_edge(size_t from, size_t to) {
        m_edges[from].emplace_back(edge(to));
    }

    inline void make_edge(size_t from, const edge_type &e) {
        m_edges[from].emplace_back(e);
    }

    inline std::vector<edge_type> edges_from(size_t v) const {
        return m_edges[v];
    }
};

// time complexity: O(V + E)
template <class Graph>
std::vector<size_t> topological_sort(const Graph &g) {

    using Edge = typename Graph::edge_type;

    std::vector<size_t> topological_orders(g.n_vertices());
    std::vector<size_t> indegrees(g.n_vertices());

    for (size_t v = 0; v < g.n_vertices(); ++v) {
        for (const Edge &e: g.edges_from(v)) {
            ++indegrees[e.to()];
        }
    }

    std::queue<size_t> q;

    for (size_t v = 0; v < g.n_vertices(); ++v) {
        if (!indegrees[v]) {
            q.push(v);
        }
    }

    for (size_t i = 0; i < g.n_vertices(); ++i) {
        if (q.empty()) { // has cycle
            return { };
        }
        size_t u = q.front();
        q.pop();
        topological_orders[i] = u;
        for (const Edge &e: g.edges_from(u)) {
            size_t v = e.to();
            --indegrees[v];
            if (!indegrees[v]) {
                q.push(v);
            }
        }
    }

    return topological_orders;
}

int main() {
    using namespace std;

    using Graph = graph<edge>;

    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        g.make_edge(s, t);
    }

    auto topological_orders = topological_sort(g);

    for (int i = 0; i < V; ++i) {
        cout << topological_orders[i] << '\n';
    }
    cout << flush;

    return 0;
}
