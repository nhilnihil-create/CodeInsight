#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main(){
  int h,n;	cin >> h >> n;
  vector<pair<int,int>>	ab(n);
  rep(i,n){
    cin >> ab[i].first >> ab[i].second;
  }
  
  vector<int> dp(h+1,1001001001);
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<h;j++){
      int nj=min(j+ab[i].first,h);
      dp[nj]=min(dp[nj],dp[j]+ab[i].second);
    }
  }
  cout << dp[h];
}