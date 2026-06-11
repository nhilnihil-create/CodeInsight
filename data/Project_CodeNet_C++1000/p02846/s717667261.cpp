
#include <cstdio>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;

int main(void) {
  ll t1, t2, a1, a2, b1, b2;
  scanf("%lld%lld%lld%lld%lld%lld", &t1, &t2, &a1, &a2, &b1, &b2);
  b1 -= a1;
  b2 -= a2;
  if(b1 == 0 || b2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  if(b1 < 0) {
    b1 *= -1;
    b2 *= -1;
  }
  ll d1 = b1 * t1;
  ll d2 = b2 * t2;
  if(d1 + d2 == 0) {
    cout << "infinity" << endl;
    return 0;
  } else if(d1 + d2 > 0) {
    cout << 0 << endl;
    return 0;
  } else {
    ll x = -(d1+d2);
    if(d1 % x == 0) {
      cout << d1 / x * 2 << endl;
    } else {
      cout << d1 / x * 2 + 1 << endl;
    }
  }
  return 0;
}
