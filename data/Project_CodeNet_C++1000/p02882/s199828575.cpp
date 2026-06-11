#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
double pi=3.141592653589793238;

int main() {
  double a,b,x;
  cin >> a >> b >> x;
  x/=a;
  if(a*b>=2*x){
      double y=2*x/b;
      double ans=atan(b/y);
      ans=ans*180/pi;
      cout << fixed << setprecision(10) << ans;
  }
  else{
      double y=(a*b-x)*2/a;
      double ans=atan(y/a);
      ans=ans*180/pi;
      cout << fixed << setprecision(10) << ans;
  }
}
