// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
#include <bits/stdc++.h>
using namespace std;

struct TopologicalSort {
  TopologicalSort () {}
  TopologicalSort (int n) : n(n), G(n), used(n, 0) {}

  int n;
  vector<vector<int>> G;
  vector<int> order, used;

  void add_edge(int u, int v) {
    G[u].push_back(v);
  }

  void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (auto to : G[v]) dfs(to);
    order.push_back(v);
  }

  void build() {
    for (int i = 0; i < n; ++i) dfs(i);
    reverse(order.begin(), order.end());
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  TopologicalSort ts(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    ts.add_edge(u, v);
  }

  ts.build();

  for (int i = 0; i < n; ++i) {
    cout << ts.order[i] << (i + 1 == n ? "\n" : " ");
  }
}