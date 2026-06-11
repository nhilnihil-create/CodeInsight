#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint S, T;
llint s[2005], t[2005];
llint dp[2005][2005], sum[2005][2005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> S >> T;
  for(int i = 1; i <= S; i++) cin >> s[i];
  for(int i = 1; i <= T; i++) cin >> t[i];

  for(int i = 1; i <= S; i++){
    for(int j = 1; j <= T; j++){
      if(s[i] == t[j]){
        dp[i][j] = sum[i-1][j-1] + 1, dp[i][j] %= mod;
      }
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mod + dp[i][j];
      sum[i][j] %= mod;
    }
  }
  cout << (sum[S][T]+1)%mod << endl;

  return 0;
}
