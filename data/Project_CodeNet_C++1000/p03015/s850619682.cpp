#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

ll dp[100005][2];

int main()
{
  string l;
  cin >> l;
  dp[0][0] = 1;
  rep(i,l.size()) {
    if (l[i] - '0' == 0) {
      /* 上の桁で以下が確定しているとき */
      (dp[i+1][1] += (dp[i][1] * 3) % MOD) %= MOD;
      /* まだ一致しているとき */
      /* (0,0) ならまだ一致 */
      (dp[i+1][0] += dp[i][0]) %= MOD;
      /* (1,0) (0,1) は一致しない */
    } else {
      /* 上の桁で以下が確定しているとき */
      (dp[i+1][1] += (dp[i][1] * 3) % MOD) %= MOD;
      /* まだ一致しているとき */
      /* (0,0) なら以下が確定 */
      (dp[i+1][1] += dp[i][0]) %= MOD;
      /* (1,0) (0,1) はまだ一致 */
      (dp[i+1][0] += (dp[i][0] * 2) % MOD) %= MOD;
    }
  }
  cout << (dp[l.size()][0] + dp[l.size()][1]) % MOD << endl;
}
