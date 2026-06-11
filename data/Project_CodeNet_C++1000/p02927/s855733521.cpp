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
  int m, d;
  cin >> m >> d;
  int ans = 0;
  rep(i, m){
    int mm = i+1;
    rep(j, d){
      int dd = j + 1;
      string s = to_string(dd);
      if(s.size() == 1) continue;
      int d1 = s.at(0) - '0';
      int d2 = s.at(1) - '0';
      if(d1 > 1 && d2 > 1 && d1*d2 == mm) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}