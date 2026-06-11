#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

template< typename T >
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
    vector< T > dist(g.size(), numeric_limits< T >::max());
    dist[s] = 0;

    using Pi = pair< T, int >;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    que.emplace(dist[s], s);

    while(!que.empty()) {
        auto cost = que.top().first;
        auto idx = que.top().second;
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    WeightedGraph<int> g(3*N);
    while(M--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[3*u].emplace_back(3*v+1, 1);
        g[3*u+1].emplace_back(3*v+2, 1);
        g[3*u+2].emplace_back(3*v, 1);
    }

    int S, T;
    cin >> S >> T;
    --S; --T;

    int dist = dijkstra(g, 3*S)[3*T];
    if(dist == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << dist/3 << endl;
    }
    return 0;
}
