#include <cstdio>  //{{{
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#define ALL(c) (c).begin(), (c).end()
#define DUMP(x) std::cerr << #x << ':' << x << '\n';

typedef long long ll;
// clang-format off
template<typename T,typename U>inline bool chmax(T&x,U a){if(x>=a)return 0;x=a;return 1;}
template<typename T,typename U>inline bool chmin(T&x,U a){if(x<=a)return 0;x=a;return 1;}
inline int in(){int x;scanf("%d", &x);return x;}
// clang-format on
// }}}

//{{{ graph.hpp
#ifndef INCLUDE_GRAPH_HPP
#define INCLUDE_GRAPH_HPP
#include <vector>
#include <climits>
namespace orliv {
namespace graph {
struct Edge {
  typedef int weight_type;
  static constexpr weight_type INF =
      std::numeric_limits<weight_type>::max() - 100;

  int from, to;
  weight_type w;
  Edge(int from, int to, weight_type w = 1) : from(from), to(to), w(w) {}
  bool operator<(const Edge& rhs) const {
    if (w != rhs.w) return w > rhs.w;
    if (from != rhs.from) return from < rhs.from;
    return to < rhs.to;
  }
};

typedef Edge::weight_type Weight;
typedef std::vector<Edge> Edges;
typedef std::vector<Weight> Weights;
typedef std::vector<int> Path;
typedef std::vector<int> Nodes;
}
typedef std::vector<graph::Edges> Graph;
}
#endif
//}}}
// {{{ topological_sort.cc
#ifndef INCLUDE_GRAPH_HPP
#include "graph.hpp"
#endif

namespace orliv {
namespace graph {
namespace topological_internal {
struct TopologicalImpl {
  const Graph& G;
  std::vector<int> color;
  Nodes order;
  TopologicalImpl(const Graph& g) : G(g), color(g.size()) {}
  Nodes get() {
    for (int v = 0; v < G.size(); v++) {
      if (!color[v] && !dfs(v)) return Nodes();
    }
    reverse(order.begin(), order.end());
    return std::move(order);
  }

 private:
  bool dfs(int v) {
    color[v] = 1;
    for (const auto& e : G[v]) {
      int u = e.to;
      if (color[u] == 2) continue;
      if (color[u] == 1) return false;
      if (!dfs(u)) return false;
    }
    order.emplace_back(v);
    color[v] = 2;
    return true;
  }
};
}

Nodes topologicalSort(const Graph& g) {
  return std::move(topological_internal::TopologicalImpl(g).get());
}
}
}
// }}}

using namespace std;

int main() {
  int V = in(), E = in();
  orliv::Graph g(V);
  for (int i = 0; i < E; i++) {
    int s = in(), t = in();
    g[s].emplace_back(s, t);
  }
  auto order = orliv::graph::topologicalSort(g);
  for (auto v : order) {
    cout << v << endl;
  }
  return 0;
}