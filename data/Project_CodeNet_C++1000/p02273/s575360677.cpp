#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i=0; i < int(n); i++)
typedef vector<int> VI;

typedef double D;      // 座標値の型。doubleかlong doubleを想定
typedef complex<D> P;  // Point
#define X real()
#define Y imag()

void print(P p) {
  cout << setprecision(8) << p.X << " " << setprecision(8) << p.Y << endl;
}

void koch(int n, P p1, P p2) {
  if (n == 0) return;
  P s = p1 + (p2-p1)*(1/3.0);
  P t = p1 + (p2-p1)*(2/3.0);
  P st = t - s;
  P u = s + st * polar(1.0, M_PI / 3);

  koch(n-1, p1, s);
  print(s);
  koch(n-1, s, u);
  print(u);
  koch(n-1, u, t);
  print(t);
  koch(n-1, t, p2);
}

int main() {
	int n;
  cin >> n;
  P p1(0,0);
  P p2(100,0);
  print(p1);
  koch(n, p1, p2);
  print(p2);

  return 0;
}