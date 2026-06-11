#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll int Dis(ll int n,ll int *dp)
{
  if(n==0)
    return 1;
  if(n==1||n==2)
    return 0;
  ll int sum=0;
  if(dp[n]!=-1)
  return dp[n]%mod;
  for(ll int i=3;i<=n;i++)
      sum = (sum%mod +  Dis(n-i,dp)%mod + mod)%mod;
      
    return dp[n] = sum%mod;
 }
int main()
{
  ll int n;
  cin>>n;
  ll int dp[n+1];
  memset(dp,-1,sizeof(dp));
  cout<<Dis(n,dp)%mod;
}