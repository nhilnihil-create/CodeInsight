#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
typedef long long ll;
using namespace std;


int main() {
  string s;
  cin>>s;
  ll mod=1e9+7,a=1,amari=0;
  ll n=s.size();
  ll dp[100100][13];
  dp[0][0]=1;
  rep(i,12) dp[0][i+1]=0;
  
  for(ll i=0; i<n; i++){
    int c=0;
    if(s[i]=='?'){
      c=-1;
    }else{
      c=s[i]-'0';
    }
    for(int j=0; j<10; j++){
      ll num=0;
      if(c!=-1&&c!=j)
        continue;
      for(int k=0; k<13; k++){
        num=(k*10+j)%13;
        dp[i+1][num]+=dp[i][k];
      }
      rep(k,13)
        dp[i+1][k]%=mod;
    }
  }
      
  cout<<dp[n][5]<<endl;   
  
}