
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

int n, m, q;

int as[51];
int bs[51];
int cs[51];
int ds[51];

int vs[15];

int go(int pos, int prev) {
  int res = 0;
  if(pos == n) {
    REP(i, q) {
      if(vs[bs[i]] - vs[as[i]] == cs[i]) {
        res += ds[i];
      }
    }
    return res;
  } else {
    for(int x = prev; x <= m; ++x) {
      vs[pos] = x;
      res = max(res, go(pos+1, x));
    }
  }
  return res;
}

int main(void) {
  cin >> n >> m >> q;
  REP(i, q) {
    cin >> as[i] >> bs[i] >> cs[i] >> ds[i];
    as[i]--;
    bs[i]--;
  }
  int res = go(0, 1);
  cout << res << endl;
  return 0;
}
