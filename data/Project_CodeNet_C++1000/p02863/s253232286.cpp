#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
#define chmax(x,y) x = max(x,y)
typedef long long ll;

int main(){
  int n,t; cin>>n>>t;
  vector<pair<int,int>> p(n);
  int dp[200005];
  rep(i,n) cin>>p[i].first>>p[i].second;
  sort(p.begin(),p.end());
  int ans = 0;
  rep(i,n){
    int a = p[i].first;
    int b = p[i].second;
    for(int j=t-1;j>=0;j--){
      chmax(ans,dp[j]+b);
      chmax(dp[j+a],dp[j]+b);
    }
  }
  cout << ans << endl;
}