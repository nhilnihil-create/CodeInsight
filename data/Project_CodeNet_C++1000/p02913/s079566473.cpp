#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=5001;
int dp[N][N];
char s[N];
int32_t main()
{
  #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
  #endif
  int n;
  cin>>n>>s;

  //dp[i][j] is longest length of prefix starting at i and j that is equal
 int ans=0;
  for(int i=n-1;i>=0;i--)
    for(int j=i;j>=0;j--)
    {
     
      if(s[i]==s[j]){dp[i][j]=dp[i+1][j+1]+1;}
      if(i-j>=dp[i][j])ans=max(ans,dp[i][j]);
      
     // cout<<i<<' '<<j<<" : "<<dp[i][j]<<"\n";
    }

    cout<<ans;

  

  
 

}