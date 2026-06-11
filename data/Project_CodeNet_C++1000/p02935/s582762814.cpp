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
  int n;
  cin >> n;
  vector<int> v(n);
  rep(snip_i, n) cin >> v.at(snip_i);
  sort(v.begin(), v.end());
  double ans = v.at(0);
  rep2(i, 1, n){
    ans = (ans + v.at(i))/2;
  }
  cout << fixed << setprecision(7) << ans << endl;
  return 0;
}