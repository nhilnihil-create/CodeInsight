#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// dijkstra
template<typename Edge>
struct dijkstra {
  using Graph = std::vector<std::vector<Edge>>;
  using T = typename Edge::cost_type;
  using GP = std::pair<T, int>;
  using Q = std::priority_queue<GP, std::vector<GP>, std::greater<GP>>;

  Graph& G;
  int N;
  std::vector<T> d;
  T INF;
  dijkstra(Graph& Graph, T inf): G(Graph), N(Graph.size()), INF(inf) {}

  void search(int s) {
    Q q;
    d.assign(N, INF);
    d[s] = 0;
    q.push(GP(0, s));
    while(!q.empty()) {
      GP p = q.top(); q.pop();
      int v = p.second;
      if(d[v] < p.first) continue;
      for(auto e: G[v]) {
        T newd = d[v]+e.cost;
        if(newd >= d[e.to]) continue;
        if(newd >= INF) continue;
        d[e.to] = newd;
        q.push(GP(d[e.to], e.to));
      }
    }
  }
};

struct edge {
  typedef int64_t cost_type;
  cost_type cost;
  int to;
  edge(cost_type c, int t): cost(c), to(t) {}
};


int main() {
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<edge>> G(N*3);
  for(int i = 0; i < M; ++i) {
    int u, v; std::cin >> u >> v; --u; --v;
    G[u].emplace_back(1, N+v);
    G[N+u].emplace_back(0, N+N+v);
    G[N+N+u].emplace_back(0, v);
  }
  dijkstra<edge> dij(G, N+N);
  int S, T; std::cin >> S >> T; --S; --T;
  dij.search(S);
  int ans = dij.d[T];
  if(ans > N) ans = -1;
  fin(ans);
  return 0;
}
