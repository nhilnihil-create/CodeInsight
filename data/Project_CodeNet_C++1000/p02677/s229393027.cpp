#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m;
  double a, b;
  cin >> a >> b >> h >> m;
 
  double x = abs((h*30+m*0.5)-(m*6));
  if(x>=180) x = 360-x;
  double pi = 3.141592653589793238;
  double ans = sqrt(a*a+b*b-2*a*b*cos(x/180*pi));
  
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}