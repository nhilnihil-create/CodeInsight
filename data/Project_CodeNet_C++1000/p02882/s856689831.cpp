#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  long double a,b,x,c; cin >>a >>b >>x;
  if(x<=a*a*b/2) c = atan2(b*b, 2*(x/a));
  else c = atan2(2*(a*b-(x/a)), a*a);
  double ans = c/(2*acos(-1))*360;
  cout << fixed << setprecision(9) << ans << endl;
  return 0;
}