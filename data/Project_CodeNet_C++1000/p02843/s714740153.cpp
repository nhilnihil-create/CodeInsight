#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll dp[100020];
  ll x;
  cin>>x;
  dp[0]=1;
  for(ll i=100;i<=x;i++){
    if(dp[i]==0 && dp[max((ll)0,i-100)]==1)dp[i]=dp[max((ll)0,i-100)];
    if(dp[i]==0 && dp[max((ll)0,i-101)]==1)dp[i]=dp[max((ll)0,i-101)];
    if(dp[i]==0 && dp[max((ll)0,i-102)]==1)dp[i]=dp[max((ll)0,i-102)];
    if(dp[i]==0 && dp[max((ll)0,i-103)]==1)dp[i]=dp[max((ll)0,i-103)];
    if(dp[i]==0 && dp[max((ll)0,i-104)]==1)dp[i]=dp[max((ll)0,i-104)];
    if(dp[i]==0 && dp[max((ll)0,i-105)]==1)dp[i]=dp[max((ll)0,i-105)];
  }
  cout<<dp[x]<<endl;
} 