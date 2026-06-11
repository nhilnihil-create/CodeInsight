// https://atcoder.jp/contests/abc169/tasks/abc169_f

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 0
#if DEBUG
  #define _GLIBCXX_DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 3000;
const int S_MAX = 3000;
const int A_I_MAX = 3000;
const int MOD = 998244353;

int N, S;
vector<int> A;

vector<int> dp;

int main() {
  cin >> N >> S;
  A = vector<int>(N);
  REP(i, N) cin >> A[i];

  dp = vector<int>(S + 1, 0);
  dp[0] = 1;

  REP(i, N) {
    for (int j = S; j >= 0; j--) {
      dp[j] = dp[j] * 2 % MOD;
      if (j >= A[i]) dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
    }
    DUMP(dp);
  }

  int ans = dp[S];
  cout << ans << endl;
}
