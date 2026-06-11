#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>> g;

int dfs(int x) {
  int ret = 1;
  vis[x] = 1;
  for (auto v : g[x]) {
    if (!vis[v]) {
      ret += dfs(v);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  g.resize(n);
  vis.resize(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      ans = max(ans, dfs(i));
    }
  }
  cout << ans << '\n';
}
