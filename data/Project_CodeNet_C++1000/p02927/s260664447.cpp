#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int m, d;
  cin >> m >> d;
  int ans = 0;
  rep2(i, 1, m+1){
    rep2(j, 11, d+1){
      int d1 = j % 10, d2 = j / 10;
      if(d1 < 2 || d2 < 2) continue;
      if(d1 * d2 == i){
        // cerr << d1 << " " << d2 << " " << i << endl;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}