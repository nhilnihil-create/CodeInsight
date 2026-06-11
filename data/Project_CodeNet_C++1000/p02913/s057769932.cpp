#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//解説写し
int dp[5005][5005];
int main() {
  int n;
  cin >>n;
  string s;
  cin>>s;
  for(int i=n-1;i>=0;--i){
    for(int j=n-1;j>=0;--j){
      if(s[i]!=s[j])dp[i][j]=0;
      else dp[i][j]=dp[i+1][j+1]+1;
    }
  }
  int kotae=0;
  rep(i,n){
    rep(j,n){
      if(i>=j)continue;
      int tmp=min(dp[i][j],j-i);
      kotae=max(kotae,tmp);
    }
  }       
  cout<<kotae<<endl;
  return 0;
}