#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int S;
  cin >> S;
  vector<long long> dp(2001);
  dp[0] = 1;
  for(int i = 0; i <= 2000; i++){
    for(int j = 0; j + 3 <= i; j++){  
      dp[i] += dp[j]; 
      dp[i] %= MOD;
    }
  }
  cout << dp[S] <<endl;
}
