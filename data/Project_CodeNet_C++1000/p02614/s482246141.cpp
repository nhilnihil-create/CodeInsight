#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> a(h);
  rep(i, h) {
    cin >> a[i];
  }
  int ans = 0;
  rep(i, 1 << h) {
    rep(j, 1 << w) {
      vector<string> c = a;
      int cnt = 0;
      rep(ii, h) {
        if (i & 1 << ii) {
          rep(jj, w) {
            c[ii][jj] = '.';
          }
        }
      }
      rep(jj, w) {
        if (j & 1 << jj) {
          rep(ii, h) {
            c[ii][jj] = '.';
          }
        }
      }
      rep(ii, h) {
        rep(jj, w) {
          if (c[ii][jj] == '#') cnt++;
        }
      }
      if (cnt == k) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
