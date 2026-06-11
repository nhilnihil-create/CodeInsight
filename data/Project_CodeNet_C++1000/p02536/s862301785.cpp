#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#define LL long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 0; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep2(i, n) for (int i = (n)-1; i > 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define newl '\n'

void dfs(int x, vector<vector<int>> &adj, vector<bool> &visited) {
  visited[x] = true;
  for (auto nxt : adj[x])
    if (!visited[nxt]) dfs(nxt, adj, visited);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> visited(n);
  int res = 0;
  rep(i, n) {
    if (!visited[i]) ++res, dfs(i, adj, visited);
  }
  cout << res - 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << fixed << setprecision(3);
  // int n;
  // cin >> n;
  // rep(i, n) solve();
  solve();
}
