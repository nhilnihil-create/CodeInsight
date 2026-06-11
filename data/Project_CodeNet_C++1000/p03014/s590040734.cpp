#include <bits/stdc++.h>

// #LIB#

using namespace std;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<vector<bool>> wall(w, vector<bool>(h));
  rep(x, w) rep(y, h) wall[x][y] = s[y][x] == '#';
  vector<vector<ll>> xcon(w, vector<ll>(h)), ycon(w, vector<ll>(h));
  rep(y, h) {
    rep(x, w) xcon[x][y] = wall[x][y] ? 0 : (x ? xcon[x - 1][y] : 0) + 1;
    for (ll x = w - 1; x > 0; --x) {
      if (!wall[x - 1][y]) updatemax(xcon[x - 1][y], xcon[x][y]);
    }
  }
  rep(x, w) {
    rep(y, h) ycon[x][y] = wall[x][y] ? 0 : (y ? ycon[x][y - 1] : 0) + 1;
    for (ll y = h - 1; y > 0; --y) {
      if (!wall[x][y - 1]) updatemax(ycon[x][y - 1], ycon[x][y]);
    }
  }
  ll ans = -1;
  rep(x, w) rep(y, h) updatemax(ans, xcon[x][y] + ycon[x][y] - 1);
  cout << ans << endl;
}
