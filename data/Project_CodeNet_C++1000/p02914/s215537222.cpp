
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

ll vs[100000+10];
ll xs[100000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  ll X = 0;
  REP(i, n) {
    scanf("%lld", &vs[i]);
    X ^= vs[i];
  }
  ll res = X;
  REP(i, n) {
    vs[i] &= ~X;
    // cerr << "> " << vs[i] << endl;
  }
  int ii = 0;
  for(int j = 59; j >= 0; --j) {
    int idx = -1;
    for(int i = ii; i < n; ++i) {
      if(vs[i] & (1LL << j)) {
        idx = i;
        break;
      }
    }
    if(idx < 0) {
      continue;
    }
    swap(vs[idx], vs[ii]);
    REP(i, n) if(i != ii && (vs[i] & (1LL << j))) {
      vs[i] ^= vs[ii];
    }
    ++ii;
  }
  ll res2 = 0;
  REP(i, ii) {
    res2 ^= vs[i];
  }
  // cerr << res << " " << res2 <<endl;
  cout << res + res2*2 << endl;
  return 0;
}
