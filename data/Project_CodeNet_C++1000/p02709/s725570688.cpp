#include<bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  ll n; cin>>n;
  vpr a(n);
  rep(i,n) {
    ll a_; cin>>a_;
    a[i] = make_pair(a_, i);
  }
  sort(ALL(a), greater<pr>());
  vector<vll> dp(n+1, vector<ll>(n+1, -1));
  dp[0][0] = 0;
  rep(tot,n) {
    pr cur = a[tot];
    repc(x,tot) {
      int y = tot - x;
      chmax(dp[x+1][y], dp[x][y] + cur.first * abs(cur.second - x));
      chmax(dp[x][y+1], dp[x][y] + cur.first * abs(cur.second - (n - 1 - y)));
    }
  }
  ll ans = -1;
  rep(i,n) chmax(ans, dp[i][n-i]);
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}