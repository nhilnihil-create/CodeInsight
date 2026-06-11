#include <cstdio>
#include <algorithm>
#include <complex>
using namespace std;

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    complex<double> p1, p2, p3, p4;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
        &p1.real(), &p1.imag(),
        &p2.real(), &p2.imag(),
        &p3.real(), &p3.imag(),
        &p4.real(), &p4.imag());
    complex<double> p5 = p2-p1;
    complex<double> p6 = p4-p3;
    if(fabs(imag(p5 * conj(p6))) < 1e-9) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}