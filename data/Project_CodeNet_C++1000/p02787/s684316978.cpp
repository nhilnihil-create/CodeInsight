#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,n,inf = 1e9;
  cin >> h >> n;
  vector<P>data(n);
  vector<int>dp(h+1,inf);
  dp[0] = 0;
  rep(i,0,n) cin >> data[i].first >> data[i].second;
  rep(i,0,h){
    rep(j,0,n){
      int pos = min(h,i+data[j].first);
      dp[pos] = min(dp[pos],dp[i]+data[j].second);
    }
  }
  cout << dp[h] << endl;
}