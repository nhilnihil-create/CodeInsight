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
  ll n, t;
  cin >> n >> t;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));
  vl dp(6010, 0);
  rep(i, n) for(ll j = t - 1; j >= 0; j--) {
    ll a = p[i].first;
    ll b = p[i].second;
    dp[j + a] = max(dp[j + a], dp[j] + b);
  }
  ll ans = 0;
  rep(i, 6010) ans = max(ans, dp[i]);
  cout << ans << endl;
}