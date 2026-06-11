#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <list>
#include <cmath>
#include <math.h>
using namespace std;

void Koch_Curve(int d, double x1, double y1, double x2, double y2) {
  if(d == 0)
    return;
  double sx = (2*x1+x2)/3, sy = (2*y1+y2)/3, tx = (x1+2*x2)/3, ty = (y1+2*y2)/3;
  double dx = tx - sx, dy = ty - sy;
  double ux = dx*cos(M_PI/3)-dy*sin(M_PI/3)+sx, uy = dx*sin(M_PI/3)+dy*cos(M_PI/3)+sy;
  
  Koch_Curve(d-1, x1, y1, sx, sy);
  cout << sx << ' ' << sy << endl;
  Koch_Curve(d-1, sx, sy, ux, uy);
  cout << ux << ' ' << uy << endl;
  Koch_Curve(d-1, ux, uy, tx, ty);
  cout << tx << ' ' << ty << endl;
  Koch_Curve(d-1, tx, ty, x2, y2);
}

int main() {
  int N;
  cin >> N;
  
  double x1 = 0.0, y1 = 0.0, x2 = 100.0, y2 = 0.0;
  cout << fixed << setprecision(8) << x1 << ' ' << y1 << endl;
  Koch_Curve(N, 0, 0, 100, 0);
  cout << x2 << ' ' << y2 << endl;

  return 0;
}