#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

using Vi = vector<int>;
using VVi = vector<Vi>;
const int INF = 1e9;

void solve() {
  int N, M, X;
  cin >> N >> M >> X;
  M++;
  VVi v(N, Vi(M));
  for (auto &e1 : v)
    for (auto &e2 : e1) cin >> e2;

  int ans = INF;
  for (int bit = 0; bit < (1 << N); bit++) {
    Vi t(M, 0);
    int sum = 0;
    rep(i, 0, N) {
      if (bit & (1 << i)) {
        sum += v[i][0];
        rep(j, 1, M) t[j] += v[i][j];
      }
    }
    bool ok = true;
    rep(k, 1, M) if (t[k] < X) ok = false;
    if (ok) ans = min(ans, sum);
  }
  cout << ((ans == INF) ? -1 : ans) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}