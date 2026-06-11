#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int DIV = 1e+9 + 7;
  string S; cin >> S;
  int N = S.size();
  long dp[N][13];
  for (int i = 0; i < 13; i++) dp[0][i] = ((S[0] == '?' && i < 10) || i == S[0] - '0');
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 13; j++) dp[i][j] = 0;
    for (int j = 0; j < 13; j++) {
      if (S[i] == '?') {
        for (int k = 0; k < 10; k++)
          dp[i][(j*10+k)%13] = (dp[i][(j*10+k)%13] + dp[i-1][j]) % DIV;
      }
      else
        dp[i][(j*10 + (S[i] - '0'))%13] = (dp[i][(j*10 + (S[i] - '0'))%13] + dp[i-1][j]) % DIV;
    }
  }
  cout << dp[N-1][5] << endl;
}