#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
long long dp[100005];;

int main() {

  long long n,m;
 cin>>n>>m;

  long long x;

  for(int i=0;i<m;i++){
     cin>>x;
     dp[x] = -1; }

  dp[0] = 1;

  if(dp[1] != -1)
    dp[1] = 1;
  else dp[1] = 0;

  for(int i=2;i<n+1;i++)
  {
     if(dp[i] == -1) dp[i] = 0;
     else {
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= mod; }
  }

  cout<<dp[n]<<endl;

return 0;
}
