#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int SMAX = 2001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int S;
  cin >> S;
  vector<long long> dp(SMAX);
  dp[3] = 1;
  for(int i = 4; i <= S; i++){  
    dp[i] = dp[i-1] + dp[i-3];
    dp[i] %= MOD;
  }
  cout << dp[S] <<endl;
}
