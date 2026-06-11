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
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> dp(n+1,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  dp[0] = 1000;
  for(int i=1;i<=n;i++){
    dp[i] = dp[i-1];
    for(int j=0;j<i;j++){
      ll val = (dp[j]/a[j])*a[i-1] + dp[j]%a[j];
      dp[i] = max(val,dp[i]);
    }
  }
  cout << dp[n]<<endl;
}
