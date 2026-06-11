#include <cstdio>
#include <algorithm>
#include <complex>
using namespace std;

int main() {
  for(int tci = 0; ; tci++) {
    complex<double> ps[3];
    complex<double> pp;
    int rr = scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
        &ps[0].real(), &ps[0].imag(),
        &ps[1].real(), &ps[1].imag(),
        &ps[2].real(), &ps[2].imag(),
        &pp.real(), &pp.imag());
    if(rr<8) break;
    bool ok = true;
    for(int i = 0; i < 3; i++) {
      double det1 = imag( (ps[(i+1)%3]-ps[i]) * conj(pp-ps[i]) );
      double det2 = imag( (ps[(i+2)%3]-ps[i]) * conj(pp-ps[i]) );
      if(det1 * det2 > 1e-9) {
        ok = false;
      }
    }
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}