#include <bits/stdc++.h>
using namespace std;

int main() {
  double a,b,h,m;
  cin >> a >> b >> h >>m;
  double sita1,sita2,A;
  if(m == 0){
    sita1 = (h*30.0);
    sita2 = 0;
  }
  else {
    sita1 = (h*30.0 + 30.0*m/60.0);
    sita2 = 360.0*m/60.0;
  }
  //cout << sita1 << endl;
  //cout << sita2 << endl;
  A = abs(sita1 - sita2)*acos(-1)/180;
  //cout << A << endl;
  cin >> a >> b >> h >> m;
  double ans = abs(sqrt(a*a+b*b-2*a*b*cos(A)));
    //cout << ans << endl;
  cout << fixed << setprecision(15) << ans << endl;
}