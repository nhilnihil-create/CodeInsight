#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  rep(i, n) cin >> s[i];
  rep(i, m) cin >> t[i];

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mod) % mod;
      if (s[i - 1] == t[j - 1]) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + 1) % mod;
    }
  }
  cout << (dp[n][m] + 1) % mod << endl;






  
  return 0;
}