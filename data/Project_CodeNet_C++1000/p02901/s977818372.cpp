#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, m;
  cin >> n >> m;
  vl a(m);
  vector<vl> c(m);
  rep(i, m) {
    ll b;
    cin >> a[i] >> b;
    rep(j, b) {
      ll cc;
      cin >> cc;
      c[i].push_back(cc - 1);
    }
  }
  vector<vl> dp(m + 1, vl(1 << n, 1e18));
  dp[0][0] = 0;
  rep(i, m) rep(s, 1 << n) {
    dp[i + 1][s] = min(dp[i + 1][s], dp[i][s]);
    ll ns = s;
    for(auto v : c[i]) ns |= (1 << v);
    dp[i + 1][ns] = min(dp[i + 1][ns], dp[i][s] + a[i]);
  }
  ll ans = dp[m][(1 << n) - 1];
  if(ans == 1e18) ans = -1;
  cout << ans << endl;
}