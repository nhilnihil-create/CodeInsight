#include <bits/stdc++.h>
using namespace std;
using Vi = vector<int>;
using VVi = vector<Vi>;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int N;
  cin >> N;
  VVi g(N, Vi(N, -1));
  rep(i, 0, N) {
    int a;
    cin >> a;
    rep(j, 0, a) {
      int x, y;
      cin >> x >> y;
      g[i][--x] = y;
    }
  }

  int ans = 0;
  for (int b = 0; b < (1 << N); b++) {
    bitset<15> bs(b);
    bool ok = true;
    rep(i, 0, N) {
      if (bs.test(i)) {
        rep(j, 0, N) {
          if (g[i][j] == -1) continue;
          if (g[i][j] != bs.test(j)) ok = false;
        }
      }
    }
    if (ok) ans = max(ans, (int)bs.count());
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}