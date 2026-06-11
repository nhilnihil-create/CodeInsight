#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  string st;
  cin>>st;
  int n=st.size();
  ll dp[100050][13], mod=1e9+7;
  if(st[0]!='?')
    dp[0][st[0]-'0']=1;
  else{
    rep(i,10)
      dp[0][i]=1;
  }
  int c;
  for(int i=1; i<n; i++){
    if(st[i]!='?') c=st[i]-'0';
    else c=-1;
    
    for(int j=0; j<10; j++){
      if(c!=-1&& c!=j) continue;
      for(int k=0; k<13; k++){
        dp[i][(k*10+j)%13]+=dp[i-1][k];
      }
    }
   for(int j=0; j<13; j++)
     dp[i][j]%=mod;
  }
  cout<<dp[n-1][5]<<endl;
    
    
  
    
}