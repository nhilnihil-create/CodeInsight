#include <bits/stdc++.h>
using namespace std;

int H, W;
char grid[110][110];

void chmin(int& a, int b) {
  if (a > b) a = b;
}
int main() {
  cin >> H >> W;

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> grid[i][j];
    }
  }
  
  int dp[110][110];
  
  
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = 10010;
    }
  }
  
  if (grid[1][1] == '#') {
    dp[1][1] = 1;
  } else {
    dp[1][1] = 0;
  }
  
  for (int i = 1; i <= H; i++) {
    if (grid[i][1] == '.' && grid[i+1][1] == '#') {
      chmin(dp[i+1][1], dp[i][1] + 1);
    } else {
      chmin(dp[i+1][1], dp[i][1]);
    }                          
  }
  

  
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (grid[i][j] == '.' && grid[i][j+1] == '#') {
        chmin(dp[i][j+1], dp[i][j] + 1);
      } else {
        chmin(dp[i][j+1], dp[i][j]);
      }
      
      if (grid[i-1][j+1] == '.' && grid[i][j+1] == '#') {
        chmin(dp[i][j+1], dp[i-1][j+1] + 1);
      } else {
        chmin(dp[i][j+1], dp[i-1][j+1]);
      }
    }
  }
  

  
  
  cout << dp[H][W] << endl;
}