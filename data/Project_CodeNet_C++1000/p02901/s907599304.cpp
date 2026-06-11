#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define ll long long
ll pow(ll x,ll y){//x^yを返す
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp;}
    y>>=1;
    tmp=tmp*tmp;
  }
  return res;
}
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> minprice(N);
  vector<int> price(M);
  vector<int> key(N);
  unordered_map<int,int> mp;
  int dp[1020][4120];
  for(int i=0;i<M;i++){
    int a,b;//値段、開けれる宝箱の数
    int rock=0;
    cin>>a>>b;
    price.at(i)=a;
    //cout<<i<<" "<<price.at(i)<<endl;
    for(int j=0;j<b;j++){
      int c;
      cin>>c;
      //vec.at(i).push_back(c);
      rock+=pow(2,c-1);
    }
    mp[i+1]=rock;
  }
  for(int i=1;i<=M;i++){
    for(int j=0;j<(1<<N);j++){
      if(j==0){dp[i][j]=0;}
      else{dp[i][j]=MOD;}
    }
  }
  for(int i=1;i<=M;i++){
    for(int j=0;j<(1<<N);j++){
      if(i>1){dp[i][j]=dp[i-1][j];}
    }
    for(int j=0;j<(1<<N);j++){
      int a=j&mp[i];
      if(a==j){
        dp[i][j]=min(dp[i][j],price.at(i-1));
      }
      else if(a==mp[i] && i>1){
        dp[i][j]=min(dp[i][j-mp[i]]+price.at(i-1),dp[i][j]);
        dp[i][j]=min(dp[i][j],dp[i-1][j]);
      }
      int c=j-a;
      if(i>1){
        dp[i][j]=min(dp[i][j],dp[i-1][c]+price.at(i-1));
      }
      //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
  }
  int b=(1<<N);
  b--;
  if(dp[M][b]!=MOD){cout<<dp[M][b]<<endl;}
  else{cout<<-1<<endl;}
}