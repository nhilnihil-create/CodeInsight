#include<bits/stdc++.h>
using namespace std;

using Weight = long long;
using Vertex = int;
struct Edge {Vertex from, to; Weight weight;};
using Graph = std::vector<std::vector<Edge>>;

std::vector<Vertex> Kahn(const Graph& G) {
  std::vector<Vertex> order;
  std::vector<int> indeg(G.size());
  for(const auto& E: G) for(const auto& e: E) ++indeg[e.to];
  std::queue<Vertex> q;
  for(Vertex v = 0; v < G.size(); ++v) if(indeg[v] == 0) q.emplace(v);
  while(!q.empty()) {
    for(const auto& e: G[q.front()]) if(--indeg[e.to] == 0) q.emplace(e.to);
    order.emplace_back(q.front());
    q.pop();
  }
  for(Vertex v = 0; v < G.size(); ++v) if(indeg[v] != 0) return {};
  return order;
}

int main() {
  int V, E;
  cin >> V >> E;
  Graph G(V);
  for(int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    G[s].push_back({s, t, 0});
  }
  for(auto v: Kahn(G)) cout << v << endl;
}

