
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

const double PI = acos(-1);

ll as[200000+10];
ll fs[200000+10];
int N;
ll K;
bool isOK(ll m) {
  ll rest = K;
  REP(i, N) {
    ll tobe = m / fs[i];
    rest -= max(0LL, as[i] - tobe);
  }
  return rest >= 0;
}

int main(void) {
  scanf("%d%lld", &N, &K);
  REP(i, N) {
    scanf("%lld", &as[i]);
  }
  REP(i, N) {
    scanf("%lld", &fs[i]);
  }
  sort(as, as + N);
  sort(fs, fs + N);
  reverse(fs, fs + N);
  ll left = -1;
  ll right = 1e18;
  while(left + 1 < right) {
    ll md = (left + right) / 2;
    if(isOK(md)) {
      right = md;
    } else {
      left = md;
    }
  }
  cout << right << endl;
  return 0;
}
