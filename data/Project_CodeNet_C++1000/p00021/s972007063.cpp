#include <complex>
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;
typedef complex<double> xy_t;
const double eps = 1e-11;
double x[4], y[4];
int N;

double cross_product(xy_t a,xy_t b) {
  return (conj(a)*b).imag()/2.0;
}

int main() {
  cin >> N; //????????°
  for (int t=0; t<N; ++t) {
    for (int i=0; i<4; ++i)
      cin >> x[i] >> y[i]; //x0,y0,...,x3,y3
    xy_t a[2] = {
      xy_t(x[0],y[0]) - xy_t(x[1],y[1]),
      xy_t(x[2],y[2]) - xy_t(x[3],y[3])
    };
    bool p = abs(cross_product(a[0],a[1])) < eps;
    cout << (p ? "YES" : "NO") << endl;
  }
}
    