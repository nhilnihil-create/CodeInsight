#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll n, m, q, t, ans = 0;
vector<ll> a, b, c, d, A;
void dfs(int dep, int num) {
  if (dep == n) {
    t = 0;
    rep(i, q) if (A[b[i]] - A[a[i]] == c[i]) t += d[i];
    ans = max(ans, t);
    return;
  }

  for (int i = num; i <= m; ++i) A[dep] = i, dfs(dep + 1, i);
}

int main() {
  cin >> n >> m >> q;
  A.resize(n);
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i], a[i]--, b[i]--;

  dfs(0, 1);
  cout << ans << endl;
  return 0;
}