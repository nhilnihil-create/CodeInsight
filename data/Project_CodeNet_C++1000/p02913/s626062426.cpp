#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,j,k;
  string s,t;
  cin>>n>>s;
  vector<int> dp(n);
  for(j=1;j<n;j++){
    t=s.substr(j-dp[j-1],dp[j-1]+1);
    for(k=0;k<j-2*dp[j-1];k++){
      if(s.substr(k,dp[j-1]+1)==t){
        dp[j]=dp[j-1]+1;
        break;
      }
    }
    if(k==j-2*dp[j-1]) dp[j]=dp[j-1];
  }
  cout<<dp[n-1]<<endl;
}