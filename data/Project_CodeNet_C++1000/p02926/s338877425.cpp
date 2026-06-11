
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

typedef complex<double> P;
inline double inp(const P& a, const P& b) {
  return (conj(a)*b).real();
}

P vs[105];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    vs[i] = P(x, y);
  }

  vector<P> cands;
  REP(i, n) {
    if(abs(vs[i]) > 0) {
      cands.push_back(vs[i]);
      cands.push_back(vs[i] * P(0, 1));
      cands.push_back(vs[i] * P(0, -1));
      cands.push_back(vs[i] * P(1, 1));
      cands.push_back(vs[i] * P(1, -1));
      REP(j, i) {
        cands.push_back(vs[i] + vs[j]);
      }
    }
  }
  double res = 0;
  for(P d : cands) {
    P cur(0, 0);
    REP(i, n) {
      if(inp(d, vs[i]) > 0) {
        cur += vs[i];
      }
    }
    res = max(res, abs(cur));
  }
  printf("%.15f\n", res);
  return 0;
}
