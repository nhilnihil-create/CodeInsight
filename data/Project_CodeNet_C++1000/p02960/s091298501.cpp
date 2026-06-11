#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;

int main(){
  int dp[100100][13];
  string S;cin>>S;
  rep(i,100100)rep(j,13){dp[i][j]=0;}
  rep(i,13)dp[0][i]=0;
  //if分岐
  dp[0][0]=1;
  for(int i=0;i<S.size();++i){
    if(S[i]=='?'){
      //?をjに変えた場合
      rep(j,13){
        rep(k,10){
          int f = (j*10+k)%13;
          dp[i+1][f]+=dp[i][j];
          dp[i+1][f]%=mod;
        }
      }
    }
    else{
      rep(j,13){
        int g = (j*10+(S[i]-'0'))%13;
        dp[i+1][g]+=dp[i][j];
        dp[i+1][g]%=mod;
      }
    }
  }
  cout << dp[S.size()][5] << endl;
}