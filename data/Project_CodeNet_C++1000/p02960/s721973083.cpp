#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  long long mod = 1e9+7;
  int n = s.length();
  long long dp[n+1][13];
  for (int i=0; i<n+1; i++) {
    for (int j=0; j<13; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  reverse(s.begin(), s.end());
  long long p10 = 1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<10; j++) {
      if (s[i] != '?' && s[i] != '0' + j) {
        continue;
      }
      long long tmp = (p10 * j) % 13;
      for (int k=0; k<13; k++) {
        dp[i+1][(tmp+k)%13] += dp[i][k];
        dp[i+1][(tmp+k)%13] %= mod;
      }
    }
    p10 *= 10;
    p10 %= 13;
  }
  cout<<dp[n][5]<<endl;
}