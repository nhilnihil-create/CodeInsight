#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
int dfs(int i, vector<vector<int>>& v) {
  int res = 1;
  vis[i] = true;
  for (int& j: v[i])
    if (! vis[j])
      res += dfs(j, v);
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vis.assign(n, false);
  vector<vector<int>> v(n);
  for (int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  
  int ans = -1;
  for (int i=0; i<n; i++) {
    if (vis[i]) continue;
    ans = max(ans, dfs(i, v));
  }
  cout << ans << endl;
  return 0;
}
