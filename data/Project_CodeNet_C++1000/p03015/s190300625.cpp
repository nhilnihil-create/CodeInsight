#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int dp[100100],dp2[100100];
signed main(){
  string L;
  cin>>L;
  dp2[0]=1;
  for(int i=1;i<=L.size();i++){
    dp[i]=dp[i-1]*3,dp2[i]=dp2[i-1];
    if(L[i-1]=='1')dp[i]+=dp2[i],dp2[i]*=2;
    dp[i]%=mod,dp2[i]%=mod;
  }
  cout<<(dp[L.size()]+dp2[L.size()])%mod<<endl;
}