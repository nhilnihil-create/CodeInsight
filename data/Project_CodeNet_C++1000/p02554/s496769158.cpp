#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define ll long long

int powmod(int a, int n) {
  int pm = 1;
  while (n > 0) {
    if (n & 1) pm = (ll)pm * a % MOD;
    a = (ll)a * a % MOD;
    n >>= 1;
  }
  return pm;
}


int main() {
  int n;
  scanf("%d", &n);

  int e10 = powmod(10, n), e9 = MOD - powmod(9, n), e8 = powmod(8, n);
  printf("%lld\n", ((ll)e10 + e9 * 2 + e8) % MOD);
  return 0;
}
