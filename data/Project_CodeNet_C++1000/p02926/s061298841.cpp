#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)

typedef long double ld;

using P = complex<ld>;

int orthant(const P & p) {
  if (p.imag() >= 0) return p.real() >= 0 ? 1 : 2;
  else return p.real() < 0 ? 3 : 4;
}

ld cross(const P & p1, const P & p2) {
  return imag(conj(p1) * p2);
}

bool argcomp(const P & p1, const P & p2) {
  int o1 = orthant(p1), o2 = orthant(p2);
  if (o1 != o2) return o1 < o2;
  return cross(p1, p2) > 0;
}

int main(){
  int N;
  cin >> N;
  vector<P> p(N);
  REP(i,N) {
    int x, y;
    cin >> x >> y;
    p[i] = P(x, y);
  }
  sort(begin(p), end(p), argcomp);

  ld ret = 0;
  REP(l,N) {
    int r = l;
    P pnow;
    REP(i,N) {
      pnow += p[r];
      ret = max(ret, abs(pnow));
      r = (r + 1) % N;
    }
  }

  cout << fixed << setprecision(12) << ret << endl;

  return 0;
}

