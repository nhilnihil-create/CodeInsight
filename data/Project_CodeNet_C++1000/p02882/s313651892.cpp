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
  double a, b, x;
  cin >> a >> b >> x;
  double ans;
  double pi = acos(-1);
  if(a*a*b/2 >= x){
    ans = x*2/a/b/b;
    ans = atan(ans);
    ans = pi/2 - ans;
  }else{
    x = a*a*b-x;
    ans = x*2/a/a/a;
    ans = atan(ans);
  }
  ans = ans*180/pi;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}