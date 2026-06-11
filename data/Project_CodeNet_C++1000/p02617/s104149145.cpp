#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> parent(n, -1);
  function<void(int,int)> dfs = [&](int u, int pa) {
    parent[u] = pa;
    for (auto v : g[u]) {
      if (v != pa) {
        dfs(v, u);
      }
    }
  };
  dfs(0, -1);

  auto count = [&](int x, int y) {
    if (x < y) {
      return 1LL * (y - x) * (n - y);
    } else {
      return 1LL * (y + 1) * (x - y);
    }
  };

  long long ans = n;
  for (int i = 1; i < n; i++) {
    ans += count(parent[i], i);
  }
  cout << ans << '\n';
  
  return 0;
}
