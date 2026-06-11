#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
main(){
   ll n,s,a,i,j,dp[6005]={1};
   cin>>n>>s;
   for(i=0;i<n;i++){
        cin>>a;
        for(j=s;j>=0;j--){
            dp[j+a]=(dp[j+a]+dp[j])%mod;
            dp[j]=dp[j]*2%mod;
        }
   }
   cout<<dp[s];
}
