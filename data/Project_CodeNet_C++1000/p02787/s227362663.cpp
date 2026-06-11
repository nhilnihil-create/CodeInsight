#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;
  vector<int> dp(H+1,2000000000);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    int ATK, CST;
    cin >> ATK >> CST;
    for (int j = 1; j <= H; j++) {
      if (j <= ATK) dp[j] = min(dp[j],CST);
      else dp[j] = min(dp[j],dp[j-ATK]+CST); 
    }
  }
  cout << dp[H] << endl;
}