#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<bool> dp(100001,false);
  for(int i=100;i<=105;i++)dp[i]=true;
  for(int i=106;i<=100001;i++)dp[i]=dp[i-100] || dp[i-101] || dp[i-102] || dp[i-103] || dp[i-104] || dp[i-105];
  int ans=dp[n]?1:0;
  cout << ans << endl;
}
