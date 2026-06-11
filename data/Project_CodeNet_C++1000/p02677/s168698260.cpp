#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
double PI = 3.1415926535897932;

int main() {
  double a,b,h,m,x,y,z;
  cin >> a >> b >> h >> m;
  
  x = 360*h/12 + 360* m/(60*12);
  y = 360*m/60;
  z = abs(x-y);
  double ans = a*a + b*b - 2*a*b*cos(z*PI/180);

  cout << fixed << setprecision(20) << sqrt(ans) << endl;
}