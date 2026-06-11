#include <iostream>
#include <string>

using namespace std;

const int M = 1e9+7;
string l;
long long dp[110000][2];

int main() {
  cin >> l;
  int len = l.length();
  
  dp[0][0] = 1;
  for (int i = 0; i < len; i++) {
    if (l[i] == '0') {
      dp[i+1][0] += dp[i][0];
    } else {
      dp[i+1][0] += dp[i][0] * 2;
      dp[i+1][1] += dp[i][0];
    }
    dp[i+1][1] += dp[i][1] * 3;
    dp[i+1][0] %= M;
    dp[i+1][1] %= M;
  }
  
  cout << (dp[len][0] + dp[len][1]) % M << endl;
  return 0;
}