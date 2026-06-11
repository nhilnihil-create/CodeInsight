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
  vector<vector<pair<int, bool>>> vp(n, vector<pair<int, bool>>());
  rep(i, n){
    int m;
    cin >> m;
    rep(j, m){
      int x, y;
      cin >> x >> y;
      x--;
      bool f = (y == 1);
      vp.at(i).push_back({x, f});
    }
  }
  int ans = 0;
  rep2(bit, 1, 1 << n){
    bool add = false;
    int co = 0;
    rep(i, n){
      if((bit & (1 << i)) != 0){
        co++;
        for(auto p : vp.at(i)){
          if(p.second == true){
            if((bit & (1 << p.first)) == 0) add = true;
          }else{
            if((bit & (1 << p.first)) != 0) add = true;
          }
        }
      }
    }
    if(add == false){
      ans = max(ans, co);
    }
  }
  cout << ans << endl;
  return 0;
}