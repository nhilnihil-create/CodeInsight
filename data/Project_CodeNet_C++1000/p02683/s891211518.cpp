#include <bits/stdc++.h>
using namespace std;
using Vi = vector<unsigned>;
using VVi = vector<Vi>;
#define rep(i, ns, ne) for (unsigned i = ns; i < ne; ++i)

unsigned N, M, X;
VVi v;
Vi p;

void input() {
  cin >> N >> M >> X;
  v.resize(N, (Vi(M)));
  p.resize(N);
  rep(i, 0, N) {
    cin >> p[i];
    rep(j, 0, M) { cin >> v[i][j]; }
  }
}
void solve() {
  // bit 全探索

  int ans = 1e9;
  for (int bit = 0; bit < (1 << N); ++bit) {
    int sum = 0;
    Vi t(M, 0);
    rep(i, 0, N) {
      if (bit & (1 << i)) {
        sum += p[i];
        rep(j, 0, M) { t[j] += v[i][j]; }
      }
    }
    // 判定
    bool ok = true;
    rep(i, 0, M) if (t[i] < X) ok = false;
    // 最小値更新
    if (ok) ans = min(ans, sum);
  }
  if (ans == 1e9) ans = -1;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  input();
  solve();
  getchar();
  return 0;
}
