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
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<int>> dp(h, vector<int>(w, inf));
  dp[0][0] = (s[0][0] == '.' ? 0 : 1);
  rep(i, h) {
    rep(j, w) {
      if (i + 1 != h) {
        if (s[i][j] == '.' && s[i + 1][j] == '#') chmin(dp[i + 1][j], dp[i][j] + 1);
        else chmin(dp[i + 1][j], dp[i][j]);
      }
      if (j + 1 != w) {
        if (s[i][j] == '.' && s[i][j + 1] == '#') chmin(dp[i][j + 1], dp[i][j] + 1);
        else chmin(dp[i][j + 1], dp[i][j]);
      }
    }
  }
  cout << dp[h - 1][w - 1] << '\n';






  
  return 0;
}