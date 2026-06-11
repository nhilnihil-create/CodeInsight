#include <bits/stdc++.h>
using namespace std;

int dp[1234567][3];

int main(){
  string s;cin>>s;
  int n=s.size();
  dp[0][1]=1;
  for(int i=0;i<n;i++){
    int a=s[i]-'0';
    dp[i+1][0]=dp[i][0]+a;
    dp[i+1][1]=min({dp[i][0]+a+1,dp[i][1]+9-a,dp[i][2]+a+1});
    dp[i+1][2]=min({dp[i][1]+10-a,dp[i][1]+a+1,dp[i][2]+a});
  }
  cout<<min(dp[n][0],dp[n][2])<<endl;
}
