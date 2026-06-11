#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,t;
  cin >> n >> t;

  vector<P> p(n);
  rep(i,n) cin >> p[i].first >> p[i].second;
  sort(p.begin(),p.end());

  vector<vector<int>> dp(n+1,vector<int>(t));
  rep(i,n){
    int a = p[i].first, b = p[i].second;
    rep(ti,t){
      if(ti<a){
        dp[i+1][ti] = dp[i][ti];
      }else{
        dp[i+1][ti] = max(dp[i][ti],dp[i][ti-a] + b);
      }
    }
  }
  int ans = 0;
  rep(i,n){
    ans = max(ans,dp[i][t-1]+p[i].second);
  }
  cout << ans << endl;
}