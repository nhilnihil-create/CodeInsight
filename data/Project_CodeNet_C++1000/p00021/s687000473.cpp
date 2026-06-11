#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
using namespace std;

typedef complex<double> P;
const double eps = 1e-8;

bool cross(P a, P b) {
  return a.real()*b.imag() - a.imag()*b.real();
}

int main() {
  int Tc;
  cin >> Tc;
  while(Tc--) {
    vector<P> ps(4);
    for(int i = 0; i < 4; ++i) {
      cin >> ps[i].real() >> ps[i].imag();
    }
    if(abs(cross(ps[1]-ps[0], ps[3]-ps[2])) < eps) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}