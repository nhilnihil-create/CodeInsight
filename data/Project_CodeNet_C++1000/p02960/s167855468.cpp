////////////////////////////////////
////////////////////////////////////
////                            ////
////                            ////
////     Please give me AC!     ////
////     Please give me AC!     ////
////                            ////
////                            ////
////////////////////////////////////
////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
const int MOD=13;
int mod_pow(int x,int y){//x^yを返す//計算量は0(log(y))
  int t=x,r=1;
  while(y){
    if(y%2){r=r*t%MOD;}
    y>>=1;
    t=t*t%MOD;
  }
  return r;
}
int main(){
  string S;
  cin>>S;
  long long dp[100020][26];
  int dpcopy[13],mod=1e9+7;
  for(int i=1;i<=(int)S.size();i++){
    if(S.at(i-1)=='?'){
      for(int j=0;j<13;j++){
        if(i==1 && j<10){
          int w=(int)S.size()-1;
          int a=mod_pow(10,w)*j;
          a%=13;
          dp[1][a]=1;
        }
        else if(i>1){
          for(int k=0;k<13;k++){
            dpcopy[k]=dp[i-1][k];
          }
          for(int k=0;k<10;k++){
            int w=(int)S.size()-i;
            int a=mod_pow(10,w)*k;
            a%=13;
            dp[i][j]+=dpcopy[(j-a+13)%13];
            dp[i][j]%=mod;
          }
          for(int k=0;k<13;k++){
            dp[i-1][k]=dpcopy[k];
          }
        }
      }
    }
    else{
      if(i==1){
        int w=(int)S.size()-i;
        int a=mod_pow(10,w)*(S.at(i-1)-'0');
        a%=13;
        dp[1][a]=1;
      }
      else{
        for(int j=0;j<13;j++){
          dpcopy[j]=dp[i-1][j];
        }
        int w=(int)S.size()-i;
        int a=mod_pow(10,w)*(S.at(i-1)-'0');
        a%=13;
        for(int j=0;j<13;j++){
          dp[i][j]=dpcopy[(j-a+13)%13];
        }
        for(int j=0;j<13;j++){
          dp[i-1][j]=dpcopy[j];
        }
      }
    }
  }
  cout<<dp[(int)S.size()][5]<<endl;
}