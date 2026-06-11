#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Edge {
  int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

vector<vector<Edge>> ReadDirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge({v1, v2}));
  }
  return graph;
}

vector<int> TopologicalSort(const vector<vector<Edge>>& graph) {
  int n = graph.size();
  vector<int> in(n);
  for (int v = 0; v < n; v++) {
    for (const auto& edge : graph[v]) {
      in[edge.to]++;
    }
  }

  deque<int> queue;
  for (int v = 0; v < n; v++) {
    if (in[v] == 0) queue.push_back(v);
  }

  vector<int> vs;
  while (!queue.empty()) {
    int v = queue.front();
    queue.pop_front();
    vs.push_back(v);
    for (const auto& edge : graph[v]) {
      in[edge.to]--;
      if (in[edge.to] == 0) queue.push_back(edge.to);
    }
  }

  if (vs.size() < n) return vector<int>();
  return vs;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  auto graph = ReadDirectedGraph(n, m);
  auto vs = TopologicalSort(graph);
  for (int v : vs) {
    cout << v << endl;
  }
}
