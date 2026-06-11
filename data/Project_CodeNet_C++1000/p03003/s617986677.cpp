#include <iostream>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define mod 1000000007

using namespace std;

llint A, B;
llint a[2005], b[2005];
llint dp[2005][2005], sum[2005][2005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  for(int i = 1; i <= A; i++) cin >> a[i];
  for(int i = 1; i <= B; i++) cin >> b[i];

  dp[0][0] = 1;
  for(int i = 0; i <= A; i++) sum[i][0] = 1;
  for(int i = 0; i <= B; i++) sum[0][i] = 1;

  for(int i = 1; i <= A; i++){
    for(int j = 1; j <= B; j++){
      if(a[i] == b[j]) dp[i][j] = sum[i-1][j-1];
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j] + mod;
      sum[i][j] %= mod;
    }
  }
  cout << sum[A][B] << endl;

  /*for(int i = 1; i <= A; i++){
    for(int j = 1; j <= B; j++){
      cout << dp[i][j] << " ";
    }
    cout<< endl;
  }
  for(int i = 1; i <= A; i++){
    for(int j = 1; j <= B; j++){
      cout << sum[i][j] << " ";
    }
    cout<< endl;
  }*/

  return 0;
}
