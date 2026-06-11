#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

const int kNil = -1;

enum class Color {
  kWhite,
  kGrey,
  kBlack,
};

template <class T>
struct Edge {
  using w_type = T;
  Edge(int u, int v, w_type w): u(u), v(v), w(w) { }
  int u, v;
  w_type w;
  bool operator<(const Edge<T> & rhs) const {
    if (w != rhs.w) { return w < rhs.w; }
    if (u != rhs.u) { return u < rhs.u; }
    return v < rhs.v;
  }
};

template <class Edge>
void DFSVisitTopological(const typename vector<Edge>::size_type node_now,
       typename vector<Edge>::size_type & time,
       const vector<vector<Edge>> & adjacency_list,
       vector<int> & d,
       vector<int> & f,
       vector<Color> & color,
       vector<int> & parent,
       stack<int> & stk) {
  color[node_now] = Color::kGrey;
  d[node_now] = time++;
  for (const auto & e: adjacency_list[node_now]) {
    if (color[e.v] == Color::kWhite) {
      parent[e.v] = node_now;
      DFSVisitTopological(e.v, time, adjacency_list, d, f, color, parent, stk);
    }
  }
  color[node_now] = Color::kBlack;
  f[node_now] = time++;
  stk.push(node_now);
}

template <class Edge>
decltype(auto) DFSTopological(const vector<Edge> & edges,
                 typename vector<Edge>::size_type node_num) {
  using size_type = typename vector<Edge>::size_type;

  vector<vector<Edge>> adjacency_list(node_num, vector<Edge>());
  for (const auto & e: edges) {
    adjacency_list[e.u].push_back(e);
  }

  vector<int> d(node_num);
  vector<int> f(node_num);
  vector<Color> color(node_num, Color::kWhite);
  vector<int> parent(node_num);
  stack<int> stk;
  size_type time = 0;

  for (unsigned i = 0; i < node_num; ++i) {
    if (color[i] == Color::kWhite) {
      DFSVisitTopological(i, time, adjacency_list, d, f, color, parent, stk);
    }
  }

  return stk;
}

int main(int argc, char const *argv[]) {
  using w_type = unsigned;

  vector<Edge<w_type>> edges;
  unsigned V, E;
  cin >> V >> E;
  for (unsigned i = 0; i < E; ++i) {
    unsigned u, v;
    w_type w;
    cin >> u >> v;
    edges.emplace_back(u, v, 1);
  }

  auto result = DFSTopological(edges, V);
  while (!result.empty()) {
    auto e = result.top();
    result.pop();
    cout << e << endl;
  }

  return 0;
}