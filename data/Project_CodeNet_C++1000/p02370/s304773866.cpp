#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> was;
vector<int> topoSort;

void dfs(int u) {
  was[u] = true;
  for (auto& v : g[u]) {
    if (!was[v]) {
      dfs(v);
    }
  }
  topoSort.push_back(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  g = vector<vector<int>>(n);
  vector<int> indeg(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    indeg[v]++;
  }
  was = vector<int>(n, false);
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      dfs(i);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << topoSort[i] << '\n';
  }
  return 0;
}

