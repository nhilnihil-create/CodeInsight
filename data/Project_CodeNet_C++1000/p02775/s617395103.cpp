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
  string s;
  cin >> s;
  reverse(all(s));
  s.push_back('0');
  ll n = s.size();
  vector<vl> dp(n + 1, vl(2, 1e18));
  dp[0][0] = 0;
  rep(i, n) rep(j, 2) rep(k, 10) {
    if(dp[i][j] == 1e18) continue;
    ll d = s[i] - '0';
    ll r = k - d - j;
    ll nj = r < 0;
    if(r < 0) r += 10;
    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + k + r);
  }
  cout << dp[n][0] << endl;
}