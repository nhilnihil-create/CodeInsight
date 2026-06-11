#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  ll N = S.size();
  ll power[N];
  power[0] = 1;
  for (ll i = 1; i < N; i++) {
    power[i] = power[i-1] * 10;
    power[i] %= 13;
  }
  ll dp[N][13];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 13; j++) {
      dp[i][j] = 0;
    }
  }
  if (S[N-1] == '?') {
    for (int i = 0; i < 10; i++) {
      dp[0][i] = 1;
    }
  } else {
    int a = S[N-1] - '0';
    dp[0][a] = 1;
  }

  for (int i = 1; i < N; i++) {
    if (S[N-i-1] != '?') {
      int a = S[N-i-1] - '0';
      int num = (power[i] * a) % 13;
      for (int j = 0; j < 13; j++) {
        dp[i][(j+num)%13] = dp[i-1][j];
      }
    } else {
      for (int j = 0; j < 13; j++) {
        for (int k = 0; k < 10; k++) {
          dp[i][((k*power[i]) + j)%13] += dp[i-1][j];
          dp[i][((k*power[i]) + j)%13] %= Mod;
        }
      }
    }
  }
  cout << dp[N-1][5] << endl;
  return 0;
}