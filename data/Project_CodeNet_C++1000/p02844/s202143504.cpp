#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  bool dp[30010][5][1010] = {};
  for (int i = 0; i < 30000; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 1000; k++) {
        dp[i][j][k] = false;
      }
    }
  }
  
  dp[0][0][0] = true;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 3; j++) {
      for (int k = 0; k < 1000; k++) {
        if (dp[i][j][k]) {
          if (j <= 2) {
          dp[i+1][j+1][10 * k + S[i] - '0'] = true;
            
          }
          dp[i+1][j][k] = true;
        }
      }
    }
  }
  
  
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    if (dp[N][3][i])  ans++;
  }
  
  cout << ans << endl;
  
  
  
  
}