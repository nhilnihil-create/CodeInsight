#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll w,h,x,y;
  cin >> w >> h >> x >> y;
  double ans=(w*h)/2.0;
  if(w%2==0 && w/2==x && h%2==0 && h/2==y)
  cout << ans << " " << 1 << endl;
  else
  cout << ans << " " << 0 << endl;
}