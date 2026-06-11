#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
#define MAXN 3100
int main(){
  string s,t;
  cin>>s>>t;
  int a=s.size(),b=t.size();
  int dp[MAXN][MAXN]={0};
  for(int i=0;i<=a;i++)dp[i][0]=i;
  for(int j=0;j<=b;j++)dp[0][j]=j;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j];
      else
      dp[i+1][j+1]=min({dp[i+1][j],dp[i][j+1],dp[i][j]})+1;
    }
  }
  cout<<dp[a][b]<<endl;
}
