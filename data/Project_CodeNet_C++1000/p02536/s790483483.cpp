#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }   
  vector<bool> vis(n);
  function<void(int)> dfs = [&](int source) {
    vis[source] = true;
    for (int to : adj[source]) {
      if (!vis[to]) {
        dfs(to);
      }
    }
  };
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {  
      ++res;
      dfs(i);
    }
  }
  cout << res - 1 << '\n';
  return 0;
}