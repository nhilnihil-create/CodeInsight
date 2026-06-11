#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
using namespace std;

typedef complex<double> P;

double cross(P a, P b) {
  return a.real()*b.imag() - a.imag()*b.real();
}

vector<P> ps(3);
P p;

bool isIn() {
  for(int i = 0; i < ps.size(); ++i) {
    P q = ps[i];
    P r = ps[(i+1)%ps.size()];
    if(cross(r-q, p-q) < 0.0) return false;
  }
  return true;
}

int main() {
  while(cin >> ps[0].real() >> ps[0].imag()) {
    for(int i = 1; i < ps.size(); ++i) {
      cin >> ps[i].real() >> ps[i].imag();
    }
    cin >> p.real() >> p.imag();
    bool flag = false;
    if(isIn() || ( swap(ps[0], ps[1]), isIn() )) {
      cout << "YES" << endl;    
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}