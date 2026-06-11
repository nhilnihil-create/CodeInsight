#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> g;
vector<int> sum;

void dfs(int now = 0, int par = -1);

int main() {
  cin >> n >> q;
  g.resize(n);
  sum.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    sum[--a] += b;
  }
  dfs();
  for (int i = 0; i < n; ++i) cout << sum[i] << " \n"[i == n - 1];
  return 0;
}

void dfs(int now, int par) {
  if (par >= 0) sum[now] += sum[par];
  for (auto to : g[now])
    if (to != par) dfs(to, now);
}