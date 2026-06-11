#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  string s;
  ll l,d,i,j,k,mod=1e9+7;
  char z;
  cin>>s;
  l=s.length();
  vector<vector<ll>> m(6,vector<ll>(13)),dp(l+1,vector<ll>(13));
  for(j=1;j<13;j++){
    m[0][j]=j;
    for(i=1;i<6;i++) m[i][j]=10*m[i-1][j]%13;
  }
  dp[0][0]=1;
  for(i=0;i<l;i++){
    z=s[l-1-i];
    if(z=='?'){
      for(d=0;d<10;d++){
        k=m[i%6][d];
        for(j=0;j<13;j++) dp[i+1][(j+k)%13]=(dp[i+1][(j+k)%13]+dp[i][j])%mod;
      }
    }
    else{
      d=z-'0';
      k=m[i%6][d];
      for(j=0;j<13;j++) dp[i+1][(j+k)%13]=dp[i][j];
    }
  }
  cout<<dp[l][5]<<endl;
}