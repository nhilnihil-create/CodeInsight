
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

const ll LIMIT = 1000000000000000000LL;

int main(void) {
  int n;
  scanf("%d", &n);
  ll r = 1;
  bool over = false;
  REP(i, n) {
    ll a;
    scanf("%lld", &a);
    if(a == 0) {
      r = 0;
      break;
    }
    if(r > LIMIT / a) {
      over = true;
    } else {
      r *= a;
    }
  }
  if(r != 0 && over) {
    r = -1;
  }
  cout << r << endl;
  return 0;
}
