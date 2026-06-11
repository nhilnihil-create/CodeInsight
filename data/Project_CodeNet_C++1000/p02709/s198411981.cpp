#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vl = vector<ll>;

int main() {
  ll n;
  cin >> n;
  vector<P> p(n);
  rep(i, n) {
    int a;
    cin >> a;
    p[i] = {a, i};
  }
  sort(all(p), greater<>());
  vector<vl> dp(n + 1, vl(n + 1, 0));
  rep(w, n) rep(i, w + 1) {
    int j = w - i;
    ll a, x;
    tie(a, x) = p[w];
    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a * abs(x - i));
    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + a * abs(n - j - x - 1));
  }
  ll ans = 0;
  rep(i, n + 1) ans = max(ans, dp[i][n - i]);
  cout << ans << endl;
}