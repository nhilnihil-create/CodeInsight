#include <bits/stdc++.h>

using namespace std;

typedef complex<double> P;

double const EPS = 1e-10;

double cross(P const& a, P const& b) {
  return imag(conj(a)*b);
}

bool is_parallel(P const& a1, P const& a2, P const& b1, P const& b2)
{ return abs(cross(a2-a1, b2-b1)) <= EPS; }

int main() {
  
  int N; cin >> N;
  for(int i=0; i<N; i++) {
    P ps[4];
    for(int i=0; i<4; i++)
      cin >> ps[i].real() >> ps[i].imag();
    printf("%s\n", (is_parallel(ps[0], ps[1], ps[2], ps[3]) ? "YES" : "NO" ));
  }
  
  return 0;
}