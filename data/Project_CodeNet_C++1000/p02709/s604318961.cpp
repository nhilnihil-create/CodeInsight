// https://atcoder.jp/contests/abc163/tasks/abc163_e

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 0
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMPP(a) REP(_i, a.size()) cout << a[_i].first << "," << a[_i].second << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMPP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 2000;
const int A_I_MAX = 1e9;

int N;
vector<pair<ll, int>> vs;
vector<vector<ll>> dp;

int main() {
  cin >> N;
  vs = vector<pair<ll, int>>(N);
  REP(i, N) {
    int A;
    cin >> A;
    vs[i] = { A, i };
  }
  sort(vs.begin(), vs.end(), greater<pair<int, int>>());

  DUMPP(vs);

  dp = vector<vector<ll>>(N + 1);
  dp[0] = vector<ll>(1, 0LL);
  REP(i, N) {
    dp[i + 1] = vector<ll>(i + 2, 0LL);
    ll A = vs[i].first;
    int k = vs[i].second;
    FOR(j, 0, i + 1) {
      if (j < i + 1) {
        int j2 = N - (i + 1) + j;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + A * abs(k - j2));
      }
      if (j > 0) {
        int j2 = j - 1;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - 1] + A * abs(k - j2));
      }
    }
  }

  DUMP2D(dp);

  ll ans = 0;
  FOR (i, 0, N) ans = max(ans, dp[N][i]);
  cout << ans << endl;
}
