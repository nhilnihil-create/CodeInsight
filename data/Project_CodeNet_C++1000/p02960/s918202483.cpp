#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dp[100000 + 1000][15];
int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  if (S[0] == '?') {
    REP(i, 10) dp[0][i] = 1;
  } else {
    dp[0][S[0] - '0']++;
  }
  int tot = 10;
  for (int i = 1; i < S.size(); i++) {
    if (S[i] == '?') {
      REP(j, 14) REP(k, 10) {
        dp[i][(j + k * tot) % 13] += dp[i - 1][j];
        dp[i][(j + k * tot) % 13] %= MOD;
      }
    } else {
      REP(j, 14) {
        dp[i][(j + (S[i] - '0') * tot) % 13] += dp[i - 1][j];
        dp[i][(j + (S[i] - '0') * tot) % 13] %= MOD;
      }
    }
    tot *= 10;
    tot %= 13;
  }
  cout << dp[S.size() - 1][5] << endl;
}