// 2020-07-25 05:27:39
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

int dp[3030], p[3030];
void answer() {
  int n, t;
  cin >> n >> t;
  vector<P> c(n);
  rep(i, n) cin >> c[i].first >> c[i].second;
  sort(ALL(c));
  int ans = 0;
  rep(i, n) {
    swap(p, dp);
    int a, b;
    tie(a, b) = c[i];
    rep(j, t) {
      dp[j] = p[j];
      if(a <= j) chmax(dp[j], p[j-a] + b);
    }
    chmax(ans, p[t-1] + b);
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}