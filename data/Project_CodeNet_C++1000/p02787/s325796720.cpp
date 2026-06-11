#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  int mx = h + 10010;
  const int INF = (int)1e9;
  vector<int> dpOld(mx, INF), dpNew(mx, INF);
  dpOld[0] = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    rep(i, mx) {
      if (i - a >= 0) {
        dpNew[i] = min(dpOld[i], dpNew[i - a] + b);
      } else {
        dpNew[i] = dpOld[i];
      }
      dpOld[i] = dpNew[i];
    }
  }
  int ans = INF;
  for (int i = h; i < mx; i++) {
    ans = min(ans, dpNew[i]);
  }
  cout << ans;
  return 0;
}