#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<pair<int,int>>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    deg[u]++; deg[v]++;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }

  auto k = max_element(deg.begin(), deg.end());
  vector<int> color(n - 1);

  function<void(int,int,int)> dfs = [&](int u, int pa, int pa_color) {
    int color_iter = 0;
    for (auto to : g[u]) {
      if (to.first == pa) continue;
      if (color_iter == pa_color) color_iter++;
      dfs(to.first, u, color_iter);
      color[to.second] = color_iter++;
    }
  };
  dfs(k - deg.begin(), -1, -1);

  cout << *k << '\n';
  for (int i = 0; i < n - 1; i++) {
    cout << color[i] + 1 << '\n';
  }
  return 0;
}
