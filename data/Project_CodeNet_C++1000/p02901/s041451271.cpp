#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> price(M);
  unordered_map<int,int> mp;
  int dp[1020][4100];
  for(int i=0;i<M;i++){
    int a,b;//値段、開けれる宝箱の数
    int rock=0;
    cin>>a>>b;
    price.at(i)=a;
    for(int j=0;j<b;j++){
      int c;
      cin>>c;
      int d=1<<(c-1);
      rock+=d;
    }
    mp[i+1]=rock;
  }
  for(int j=0;j<(1<<N);j++){
    if(j==0){dp[1][j]=0;}
    else{dp[1][j]=MOD;}
  }
  for(int i=1;i<=M;i++){
    for(int j=0;j<(1<<N);j++){
      if(i>1){dp[i][j]=dp[i-1][j];}
      int a=j&mp[i],c=j-(j&mp[i]);
      if(a==j){dp[i][j]=min(dp[i][j],price.at(i-1));}
      else if(a==mp[i] && i>1){dp[i][j]=min(dp[i][j-mp[i]]+price.at(i-1),dp[i][j]);}
      if(i>1){dp[i][j]=min(dp[i][j],dp[i-1][c]+price.at(i-1));}
    }
  }
  if(dp[M][(1<<N)-1]!=MOD){cout<<dp[M][(1<<N)-1]<<endl;}
  else{cout<<-1<<endl;}
}