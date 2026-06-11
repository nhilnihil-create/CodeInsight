#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n, t;
  cin >> n >> t;
  vector<P> food(n);
  rep(i,n) cin >> food[i].first >> food[i].second;

  vector<vector<ll>> dp(t+1,vector<ll>(2,0));
  
  for (int i = 0; i < n; i++) {
    int a = food[i].first, b = food[i].second;
    vector<vector<ll>> ndp(t+1,vector<ll>(2,0));
    for (int j = 0; j < t; j++) {
      ndp[j][0] = max(dp[j][0], ndp[j][0]);
      ndp[j][1] = max(dp[j][1], ndp[j][1]);
      ndp[j][1] = max(dp[j][0] + b, ndp[j][1]);
      if (j + a < t) {
        ndp[j + a][0] = max(ndp[j + a][0], dp[j][0] + b);
        ndp[j + a][1] = max(ndp[j + a][1], dp[j][1] + b);   
      }     
    }
    swap(dp, ndp);
  }
  cout << dp[t-1][1] << endl;
  return 0;  
} 