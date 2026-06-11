#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<pair<int, int>> vp;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    vp.emplace_back(a, b);
  }

  map<P, int> ans;
  vector<int> cs(n, 0);
  vector<bool> used(n, false);
  queue<int> q;
  used[0] = true;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    int c = 1;
    for (int u : g[v]) {
      if (used[u]) continue;
      if (c == cs[v]) c++;
      cs[u] = ans[P(u, v)] = ans[P(v, u)] = c++;
      used[u] = 1;
      q.emplace(u);
    }
  }

  int k = 0;
  rep(i, n - 1) k = max(k, (int)g[i].size());
  cout << k << endl;
  for (auto p : vp) cout << ans[p] << endl;
  return 0;
}
