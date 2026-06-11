#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n, t;
  cin >> n >> t;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));
  vi a(n), b(n);
  rep(i, n) {
    a[i] = p[i].first;
    b[i] = p[i].second;
  }
  int dp[n + 1][t][2] = {};
  rep(i, n + 1) rep(j, t) rep(k, 2) dp[i][j][k] = -1;
  dp[0][0][0] = 0;
  rep(i, n) rep(j, t) rep(k, 2) {
    if(dp[i][j][k] == -1) continue;
    int ni = i + 1;
    int nj = j + a[i];
    dp[ni][j][k] = max(dp[ni][j][k], dp[i][j][k]);
    if(k) {
      if(nj < t) dp[ni][nj][1] = max(dp[ni][nj][1], dp[i][j][1] + b[i]);
    } else {
      if(nj < t)
        dp[ni][nj][0] = max(dp[ni][nj][0], dp[i][j][0] + b[i]);
      else
        dp[ni][j][1] = max(dp[ni][j][1], dp[i][j][0] + b[i]);
    }
  }
  int ans = 0;
  rep(j, t) rep(k, 2) ans = max(ans, dp[n][j][k]);
  cout << ans << endl;
}