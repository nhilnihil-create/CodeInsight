#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<char>> vec;
int main(){
  ll H,W;
  cin>>H>>W;
  ll dp[101][101];
  vec.resize(H,vector<char>(W));
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      cin>>vec.at(i).at(j);
    }
  }
  dp[1][1]=0;
  if(vec.at(0).at(0)=='#'){dp[1][1]++;}
  for(ll i=1;i<=H;i++){
    for(ll j=1;j<=W;j++){
      if(i==1&&j==1){
      }else if(i==1&&j!=1){
        dp[1][j]=dp[1][j-1];
        if(vec.at(0).at(j-1)=='#'&&vec.at(0).at(j-2)=='.'){dp[1][j]++;}
      }else if(i!=1&&j==1){
        dp[i][1]=dp[i-1][1];
        if(vec.at(i-1).at(0)=='#'&&vec.at(i-2).at(0)=='.'){dp[i][1]++;}
      }else{
        ll a=dp[i][j-1];
        if(vec.at(i-1).at(j-1)=='#'&&vec.at(i-1).at(j-2)=='.'){a++;}
        ll b=dp[i-1][j];
        if(vec.at(i-1).at(j-1)=='#'&&vec.at(i-2).at(j-1)=='.'){b++;}
        dp[i][j]=min(a,b);
      }
    }
  }
  cout<<dp[H][W]<<endl;
}