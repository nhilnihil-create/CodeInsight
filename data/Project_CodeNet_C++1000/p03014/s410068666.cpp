#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> G(h);
  rep(i, h) {
    string s;
    cin >> s;
    G[i] = s;
  }
  int sum[h][w] = {};
  rep(i, h) {
    int befor = 0, cnt = 0;
    rep(j, w) {
      if (G[i][j] == '.') {
        cnt++;
      } else {
        for (int k = befor; k < befor + cnt; ++k) {
          sum[i][k] += cnt;
        }
        befor = j + 1;
        cnt = 0;
      }
    }
    for (int k = befor; k < befor + cnt; ++k) {
      sum[i][k] += cnt;
    }
  }
  rep(i, w) {
    int befor = 0, cnt = 0;
    rep(j, h) {
      if (G[j][i] == '.') {
        cnt++;
      } else {
        for (int k = befor; k < befor + cnt; ++k) {
          sum[k][i] += cnt;
        }
        befor = j + 1;
        cnt = 0;
      }
    }
    for (int k = befor; k < befor + cnt; ++k) {
      sum[k][i] += cnt;
    }
  }
  /* rep(i, h) {
    rep(j, w) cout << sum[i][j];
    cout << endl;
  } */
  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, sum[i][j]);
  cout << ans - 1 << endl;
  return 0;
}
