// 2020-07-25 02:35:32
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

void answer() {
  int n, t;
  cin >> n >> t;
  deque<P> c;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    c.emplace_back(P(b, a));
  }
  sort(c.rbegin(), c.rend());
  {
    auto first = c.front(); c.pop_front();
    c.emplace_back(first);
  }
  vector<vector<int> > dp(n+1, vector<int>(t, 0));
  rep(i, n) {
    int a, b;
    tie(b, a) = c[i];
    rep(j, t) {
      dp[i+1][j] = dp[i][j];
      if(a <= j) chmax(dp[i+1][j], dp[i][j-a] + b);
    }
  }
  int v = dp[n][t-1], w = t-1;
  multiset<int> remain;
  remain.insert(0);
  REPCM(i, n-1, 0) {
    int a, b;
    tie(b, a) = c[i];
    if(dp[i][w-a] + b == v) {
      v -= b;
      w -= a;
    } else {
      remain.insert(b);
    }
  }
  int ans1 = dp[n-1][t-1] + c.back().first;
  int ans2 = dp[n][t-1] + (*(remain.rbegin()));
  cout << max(ans1, ans2) << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}