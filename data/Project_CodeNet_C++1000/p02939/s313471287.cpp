#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 2e5 + 5;

int dp [MAX_N][3];

int main () {
  ios::sync_with_stdio(false);

  string str;
  cin >> str;

  int n = str.size();

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  dp[0][1] = 1;
  dp[0][2] = -MAX_N;

  dp[1][1] = (str[0] == str[1] ? -MAX_N : 2);
  dp[1][2] = 1;
  
  for (int i = 2; i < n; i++) {
    dp[i][1] = 1 + dp[i - 1][2];
    if (str[i] != str[i - 1]) {
      dp[i][1] = max(dp[i][1], 1 + dp[i - 1][1]);
    }

    dp[i][2] = 1 + dp[i - 2][1];
    if (i >= 3) {
      if (str[i] != str[i - 2] || str[i - 1] != str[i - 3]) {
        dp[i][2] = max(dp[i][2], 1 + dp[i - 2][2]);
      }
    }
  }

  cout << max(dp[n - 1][1], dp[n - 1][2]) << endl;
}
