#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> v(h);
  rep(i, h) cin >> v[i];
  int ans = 0;
  rep(is, 1 << h) rep(js, 1 << w) {
    int count = 0;
    rep(i, h) rep(j, w) {
      if (is >> i & 1) continue;
      if (js >> j & 1) continue;
      if (v[i][j] == '#') count++;
    }
    if (count == k) ans++;
  }
  cout << ans << endl;
  return 0;
}