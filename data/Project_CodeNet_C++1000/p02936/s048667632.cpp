#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long ll;

const int N = 2 * 1e5 + 5;
int n, q, a, b;
vector<vector<int>> r;
vector<int> ans;

void dfs(int v, int p = -1) {
  for (int u : r[v]) {
    if (u == p) continue;
    ans[u] += ans[v];
    dfs(u, v);
  }
}

int main() {
  cin >> n >> q;
  int p, x;
  r.resize(n);
  ans.resize(n);
  rep(i, n - 1) cin >> a >> b, a--, b--, r[a].push_back(b), r[b].push_back(a);
  rep(i, q) cin >> p >> x, p--, ans[p] += x;
  dfs(0);
  rep(i, n) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
