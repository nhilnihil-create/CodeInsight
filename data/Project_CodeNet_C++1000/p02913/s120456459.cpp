#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<int>> dp(n, vector<int>(n));
  rep(i, n){
    int add = 0;
    if(s.at(n-1) == s.at(i)) add = 1;
    dp.at(i).at(n-1) = dp.at(n-1).at(i) = add;
  }

  rrep(i, n-1){
    rrep(j, n-1){
      int add = 0;
      if(s.at(i) == s.at(j)) add = dp.at(i+1).at(j+1) + 1;
      dp.at(i).at(j) = add;
    }
  }

  int ans = 0;
  rep(i, n){
    rep(j, n){
      int add = min(abs(i-j), dp.at(i).at(j));
      ans = max(ans, add);
    }
  }
  cout << ans << endl;
  return 0;
}