#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1010;
int id[N][N];
int vis[N * N];
int dist[N * N];
vector<int> g[N * N];
int dfs (int cur) {
  int res = 0;
  for (int nxt : g[cur]) {
    if (vis[nxt] == 1) {
      cout << -1 << endl;
      exit(0);
    } else if (vis[nxt] == 2) {
      res = max(res, dist[nxt]);
    } else {
      vis[nxt] = 1;
      res = max(res, dfs (nxt));
    }
  }
  vis[cur] = 2;
  return dist[cur] = res + 1;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int c = 0;
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) id[i][j] = id[j][i] = c++;
  vector<vector<int>> in(n, vector<int>(n - 1));
  for (int i = 0; i < n; i++) for (int j = 0; j < n - 1; j++) {
    cin >> in[i][j];
    in[i][j]--;
    in[i][j] = id[i][in[i][j]];
  }
  for (int i = 0; i < n; i++) for (int j = 0; j + 1 < n - 1; j++) g[in[i][j]].push_back(in[i][j + 1]);
  int ans = 0;
  for (int i = 0; i < c; i++) {
    ans = max(ans, dfs(i));
  }
  cout << ans << endl;
  return 0;
}