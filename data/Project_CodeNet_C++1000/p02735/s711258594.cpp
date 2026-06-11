#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[110][110];

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<bool>> v(h,vector<bool>(w));
  rep(i,h)rep(j,w) {
    char c;
    cin >> c;
    if(c=='#') v[i][j] = false;
    else v[i][j] = true;
  }
  rep(i,h)rep(j,w) {
    ll a = 1e18;
    ll l = 1e18;
    if(i==0 && j==0) {
      if(!v[i][j]) dp[i][j] = 1LL;
      continue;
    }
    if(i!=0) {
      a = dp[i-1][j];
      if(!v[i][j] && v[i-1][j]) a++;
    }
    if(j!=0) {
      l = dp[i][j-1];
      if(!v[i][j] && v[i][j-1]) l++;
    }
    dp[i][j] = min(a,l);
  }
  cout << dp[h-1][w-1] << endl;
  return 0;
}