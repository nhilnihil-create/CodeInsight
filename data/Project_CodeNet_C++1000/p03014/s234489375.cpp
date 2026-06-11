#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}

const ll MAX = 2020;
ll dpL[MAX][MAX] = {};
ll dpR[MAX][MAX] = {};
ll dpU[MAX][MAX] = {};
ll dpD[MAX][MAX] = {};

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> st(h);
  for (ll i = 0; i < h; i++) cin >> st[i];

  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      if (st[i][j] == '#') continue;
      dpL[i][j] = (j ? dpL[i][j - 1] : 0) + 1;
      dpU[i][j] = (i ? dpU[i - 1][j] : 0) + 1;
    }
  }
  for (ll i = h - 1; i >= 0; i--) {
    for (ll j = w - 1; j >= 0; j--) {
      if (st[i][j] == '#') continue;
      dpR[i][j] = (j + 1 < w ? dpR[i][j + 1] : 0) + 1;
      dpD[i][j] = (i + 1 < h ? dpD[i + 1][j] : 0) + 1;
    }
  }

  ll ans = 0;
  for (ll i = 0; i < h; i++)
    for (ll j = 0; j < w; j++)
      if (st[i][j] == '.')
        chmax(ans, dpL[i][j] + dpR[i][j] + dpU[i][j] + dpD[i][j] - 3);

  cout << ans << endl;
  return 0;
}
