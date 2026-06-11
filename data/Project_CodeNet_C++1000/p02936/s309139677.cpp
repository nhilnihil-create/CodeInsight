#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> cost;
vector<int> ans;
vector<vector<int>> G;

void dfs(int node, int from) {
  ans[node] = cost[node];
  if (node != 0)
    ans[node] += ans[from];
  for (auto g : G[node]) {
    if (g == from)
      continue;
    dfs(g, node);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  cost.resize(n);
  ans.resize(n);
  G.resize(n);

  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, 0, q) {
    int p, x;
    cin >> p >> x;
    p--;
    cost[p] += x;
  }

  dfs(0, -1);
  rep(i, 0, n) {
    if (i > 0)
      cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
