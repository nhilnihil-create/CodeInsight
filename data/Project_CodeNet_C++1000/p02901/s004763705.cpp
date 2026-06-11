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
#define rep(i,n) for(ll i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  
  vector<ll> dp(1<<n,-1);
  dp[0] = 0;
  rep(mi,m){
    ll a,b; ll c = 0;
    cin >> a >> b;
    rep(bi,b){
      int ci;
      cin >> ci;
      c |= 1<<(ci-1);
    }
    rep(i,1<<n){
      if(dp[i]==-1) continue;
      ll ni = i|c;
      dp[ni] = dp[ni] == -1
             ? dp[i] + a
             : min(dp[ni],dp[i] + a);
    }
  }
  cout << dp[(1<<n)-1] << endl;
}
