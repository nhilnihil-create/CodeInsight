#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
  string N;
  cin >> N;
  ll dp[1000002][2];
  dp[0][1] = 1;
  dp[0][0] = 0;

  for(int i = 0; i < (int)N.size(); i++) {
    int n = N[i]-'0';
    dp[i+1][0] = min(dp[i][0]+n, dp[i][1]+10-n);
    dp[i+1][1] = min(dp[i][0]+n+1, dp[i][1]+10-n-1);
  }
  
  cout << dp[N.size()][0] << endl;  
  return 0;
}