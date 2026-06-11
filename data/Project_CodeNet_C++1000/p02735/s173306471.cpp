#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll dx[] = {1, 0};
ll dy[] = {0, 1};

int main() {
  ll h, w;
  cin >> h >> w;
  string s[h];
  ll ans[h][w] = {};
  rep(i, h) rep(j, w) ans[i][j] = INF;
  rep(i, h) cin >> s[i];
  ans[0][0] = 0 + (s[0][0] == '#' ? 1 : 0);

  rep(i, h) rep(j, w) rep(k, 2) {
    ll ny = i + dy[k];
    ll nx = j + dx[k];
    if (nx < w && ny < h)
      ans[ny][nx] =
          min(ans[i][j] + (s[ny][nx] == '#' && s[i][j] == '.' ? 1 : 0),
              ans[ny][nx]);
  }

  // rep(i, h) {
  //   rep(j, w) { cout << ans[i][j] << " "; }
  //   cout << endl;
  // }

  cout << ans[h - 1][w - 1] << endl;
  return 0;
}
