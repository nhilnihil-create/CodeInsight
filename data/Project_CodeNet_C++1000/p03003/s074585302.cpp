#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,m;
  cin >> n >> m;
  vector<ll> s(n),t(m);
  repr(i, n, 0) cin >> s[i];
  repr(i, m, 0) cin >> t[i];

  vector<vector<ll>> sum(n+1, vector<ll>(m+1, 0));
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

  // 空集合
  dp[0][0] = 0;
  sum[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j]) {
        dp[i+1][j+1] = sum[i][j] + 1;
        dp[i+1][j+1] %= mod;
      } else {
        dp[i+1][j+1] = 0;
      }

      sum[i+1][j+1] = (sum[i+1][j] + sum[i][j+1] + dp[i+1][j+1]) % mod;
      sum[i+1][j+1] = (sum[i+1][j+1] + mod - sum[i][j]) % mod;
      sum[i+1][j+1] %= mod;
    }
  }

  ll ans = 1;
  for (int i = 0; i < n+1; ++i) {
    for (int j = 0; j < m+1; ++j) {
      ans += dp[i][j];
      ans %= mod;
    }
  }
  cout << ans << endl;
}