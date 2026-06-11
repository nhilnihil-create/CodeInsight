#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod ll(1e9+7)
#define inf ll(1e9)
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
   int n,m;
   cin>>n>>m;
   map<int,int>rel;
   for(int i=0; i<m; i++){
    int num;
    cin>>num;
    rel[num]=1;
   }
   vector<ll>dp(n+1);
   dp[0]=1;
   for(int i=1; i<=n; i++){
    if(rel.count(i))
      dp[i]=0;
    else{
      dp[i]=dp[i-1];
      if(i>=2)
        dp[i]=(dp[i]+dp[i-2])%mod;
    }
   }
   cout<<dp[n];
   return 0;

   
   
}