#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int mod=1e9+7;
const int N=1e5+3;
int dp[N];
bool bad[N];
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif

  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x;cin>>x;
    bad[x]=1;
  }

  dp[1]=1;dp[2]=1;
  if(bad[1])dp[1]=0;
  dp[2]=1+dp[1];
  if(bad[2])dp[2]=0;
  for(int i=3;i<=n;i++)
  {
    if(bad[i])dp[i]=0;
    else dp[i]=(dp[i-1]+dp[i-2])%mod;
  }
 // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
  cout<<dp[n]<<"\n";
}