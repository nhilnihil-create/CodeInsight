#include <bits/stdc++.h>
using namespace std;

int main () {
  double a,b,x;
  cin >> a >> b >> x;
  double h = 1.0*x/(a*a);
  if (b == h*2){
    cout << 45 << endl;
    return 0;
  }
  
  double A;
  if (b > h*2){
    A = atan(a*h*2/(b*b));
  }
  else {
    A = atan(a/(b*2-h*2));
  }
  double ans = 90 - A*180/M_PI;
  printf("%.8lf\n", ans);
}