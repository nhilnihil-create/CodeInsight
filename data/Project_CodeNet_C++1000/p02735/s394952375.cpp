#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<char>> vec;
int main(){
  ll H,W,ans=0;
  cin>>H>>W;
  ll dp[111][111];
  vec.resize(H,vector<char>(W));
  vector<vector<ll>> answer(H,vector<ll>(W));
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      cin>>vec.at(i).at(j);
    }
  }
  if(vec.at(0).at(0)=='#'){ans++;}
  for(ll i=1;i<=H;i++){
    for(ll j=1;j<=W;j++){
      if(i==1&&j==1){
        dp[i][j]=0;
      }else if(i==1&&j!=1){
        dp[i][j]=dp[i][j-1];
        if(vec.at(i-1).at(j-1)=='#'&&vec.at(i-1).at(j-2)=='.'){dp[i][j]++;}
      }else if(i!=1&&j==1){
        dp[i][j]=dp[i-1][j];
        if(vec.at(i-1).at(j-1)=='#'&&vec.at(i-2).at(j-1)=='.'){dp[i][j]++;}
      }else{
        ll a;
        a=dp[i][j-1];
        if(vec.at(i-1).at(j-1)=='#'&&vec.at(i-1).at(j-2)=='.'){a++;}
        ll b;
        b=dp[i-1][j];
        if(vec.at(i-1).at(j-1)=='#'&&vec.at(i-2).at(j-1)=='.'){b++;}
        dp[i][j]=min(a,b);
      }
    }
  }
  cout<<dp[H][W]+ans<<endl;
}