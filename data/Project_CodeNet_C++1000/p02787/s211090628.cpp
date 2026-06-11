#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}


int main() {
  int H, N;
  cin >> H >> N;
  
  vector<int> A(1010), B(1010);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  
  vector<int> dp(20100, 100000000);
  
  dp[0] = 0;
  
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < N; j++) {
      chmin(dp[i+ A[j]], dp[i] + B[j]);
    }
  }
  
  int ans = dp[H];
  for (int i = H; i <= 20000; i++) {
    chmin(ans, dp[i]);
  }
  
  cout << ans << endl;
  
    
  
}