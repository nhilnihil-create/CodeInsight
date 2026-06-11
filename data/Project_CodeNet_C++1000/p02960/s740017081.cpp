#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

string s;
ll dp[100010][15];

int main()
{
  cin >> s;
  dp[0][0] = 1;
  int n = (int)s.size();
  REP(i, n) {
    REP(j, 13)
    if (s[i] == '?') {
      REP(k, 10) {
        (dp[i + 1][(j * 10 + k) % 13] += dp[i][j]) %= MOD;;

      } 
    } else {
      int x = s[i] - '0';
      (dp[i + 1][(j * 10 + x) % 13] += dp[i][j]) %= MOD;
    }
  }
  cout << dp[n][5];
  return 0;
}