#include <iostream>
#include <string>

using namespace std;

const int M = 1e9+7;
string s;
long long dp[110000][13];

int main()
{
  cin >> s;
  int len = s.length();
  
  dp[0][0] = 1;
  
  for (int i = 0; i < len; i++) {
    for (int rem = 0; rem < 13; rem++) {
      if (s[i] != '?') {
        int next_rem = (rem * 10 + (s[i] - '0')) % 13;
        dp[i+1][next_rem] += dp[i][rem];
        dp[i+1][next_rem] %= M;
      } else {
        for (int num = 0; num < 10; num++) {
          int next_rem = (rem * 10 + num) % 13;
          dp[i+1][next_rem] += dp[i][rem];
          dp[i+1][next_rem] %= M;
        }
      }
    }
  }
  
  cout << dp[len][5] << endl;
  return 0;
}