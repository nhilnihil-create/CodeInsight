#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  const int INF=100000000;
  int n,t,dp[3010][3010],i,j;
  cin >> n >> t;
  vector<P> a(n);
  for(i=0;i<n;i++){
    cin >> a[i].first >> a[i].second;
  }
  for(i=0;i<=n;i++){
    for(j=0;j<=t;j++){
      dp[i][j]=-INF;
    }
  }
  sort(a.begin(),a.end());
  dp[0][0]=0;
  for(i=0;i<n;i++){
    for(j=0;j<=t;j++){
      if(j==t){
        dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
        continue;
      }
      if(j+a[i].first>t){
        dp[i+1][t]=max(dp[i+1][t],dp[i][j]+a[i].second);
      }
      else{
        dp[i+1][j+a[i].first]=max(dp[i+1][j+a[i].first],dp[i][j]+a[i].second);
      }
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
    }
  }
  int ans=0;
  for(i=0;i<=t;i++){
    ans=max(ans,dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}