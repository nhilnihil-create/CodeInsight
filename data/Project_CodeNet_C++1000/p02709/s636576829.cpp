// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
ll score(P x,ll i){
  return abs(i-x.second)*x.first;
}
signed main(){
  init_io();
  ll n,ans=0;
  cin >> n;
  vector<P> a(n);
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
  for(int i=0;i<n;i++){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(),a.end(),greater<P>());
  for(int i=0;i<n;i++){
    for(int l=0;l<=i+1;l++){
      ll r = i+1-l;
      if(l!=0){
        dp[l][r] = max(dp[l-1][r]+score(a[i],l-1),dp[l][r]);
      }
      if(r!=0){
        dp[l][r] = max(dp[l][r-1]+score(a[i],n-r),dp[l][r]);
      }
      ans = max(ans,dp[l][r]);
    }
  }
  cout << ans << endl;
}
