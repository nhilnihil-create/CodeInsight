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
  int dp[t][2] = {};
  rep(i, n) for(int j = t - 1; j >= 0; j--) rep(k, 2) {
    if(dp[j][k] == -1) continue;
    int nj = j + a[i];
    if(k) {
      if(nj < t) dp[nj][1] = max(dp[nj][1], dp[j][1] + b[i]);
    } else {
      if(nj < t)
        dp[nj][0] = max(dp[nj][0], dp[j][0] + b[i]);
      else
        dp[j][1] = max(dp[j][1], dp[j][0] + b[i]);
    }
  }
  int ans = 0;
  rep(j, t) rep(k, 2) ans = max(ans, dp[j][k]);
  cout << ans << endl;
}
