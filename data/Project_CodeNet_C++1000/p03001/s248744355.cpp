#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  double w,h,x,y; cin >>w >>h >>x >>y;
  double ans = w*h/2;
  cout << fixed << setprecision(6) << ans << ' ';
  if(x*2==w && y*2==h)cout << 1;
  else cout << 0;
  cout << endl;
  return 0;
}