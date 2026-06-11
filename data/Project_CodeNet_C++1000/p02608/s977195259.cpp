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
  vector<int> ans(n+1, 0);
  for(ll x = 1; x <= n; x++){
    if(x*x > n) break;
    for(ll y = 1; y <= n; y++){
      if(x*x+y*y+x*y > n) break;
      for(ll z = 1; z <= n; z++){
        ll add = x*x + y*y + z*z + x*y + y*z + z*x;
        if(add > n) break;
        ans.at(add)++;
      }
    }
  }
  rep2(i, 1, n+1){
    cout << ans.at(i) << endl;
  }
  return 0;
}