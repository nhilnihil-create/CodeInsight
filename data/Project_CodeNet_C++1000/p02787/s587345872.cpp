#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,n,inf = 1e9;
  cin >> h >> n;
  vector<int>a(n),b(n),dp(h+1,inf);
  rep(i,0,n) cin >> a[i] >> b[i];
  dp[0] = 0;
  rep(i,0,h+1){
    if(dp[i] == inf) continue;
    rep(j,0,n){
      int pos = i+a[j];
      if(pos >= h) pos = h;
      dp[pos] = min(dp[pos],dp[i]+b[j]);
    }
  }
  cout << dp[h] << endl;
}