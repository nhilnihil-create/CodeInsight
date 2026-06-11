#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

typedef pair<float, float> point;
const float rad = (M_PI*60) / 180.0;
int n;

void koch(int d, point p1, point p2) {
  if (!d) return;

  float sx = (2*p1.first + 1*p2.first) / 3;
  float sy = (2*p1.second + 1*p2.second) / 3;
  float tx = (1*p1.first + 2*p2.first) / 3;
  float ty = (1*p1.second + 2*p2.second) / 3;
  float ux = (tx-sx)*cos(rad) - (ty-sy)*sin(rad)+sx;
  float uy = (tx-sx)*sin(rad) + (ty-sy)*cos(rad)+sy;
  
  cout << fixed << setprecision(10);

  koch(d-1, p1, point(sx, sy));
  cout << sx << ' ' << sy << endl;

  koch(d-1, point(sx, sy), point(ux, uy));
  cout << ux << ' ' << uy << endl;

  koch(d-1, point(ux, uy), point(tx, ty));
  cout << tx << ' ' << ty << endl;

  koch(d-1, point(tx, ty), p2);
}

int main() {
  cin >> n;

  cout << fixed << setprecision(10);
  cout << 0.0 << ' ' << 0.0 << endl;  
  koch(n, point(0, 0), point(100, 0));
  cout << 100.0 << ' ' << 0.0 << endl;  
  return 0;
}