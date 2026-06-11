#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n, m, q;
vector<vector<int>> vx;
void all_dfs(int i, int p, vector<int> v) {
  if (i == n) {
    vx.push_back(v);
    return;
  }

  rep(j, p, m + 1) {
    vector<int> nv = v;
    nv.push_back(j);
    all_dfs(i + 1, j, nv);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> q;

  vector<int> v;
  all_dfs(0, 1, v);

  vector<int> a(q), b(q), c(q), d(q);
  rep(i, 0, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

  ll ans = 0;
  rep(i, 0, vx.size()) {
    ll cost = 0;
    rep(j, 0, q) {
      if (vx[i][b[j] - 1] - vx[i][a[j] - 1] == c[j])
        cost += d[j];
    }
    chmax(ans, cost);
  }

  cout << ans << endl;
}
