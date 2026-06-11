#include <algorithm>
#include <cstdio>

#define int long long
#define dotimes(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

signed main() {
  int N = rint();
  int M = rint();
  // b_k := a_k / 2
  // a_k * (p + 0.5) = b_k * (2 * p + 1)
  // So semi-cm of b_k
  // - doesn't exist if LCM of (b_k) / b_k is even for any k
  // - is an odd multiple LCM of (b_k) otherwise
  int b[N];
  dotimes(i, N)
    b[i] = rint() / 2;
  int p = b[0];
  dotimes(i, N-1) {
    int q = b[i+1];
    p = p / __gcd(p, q) * q;
  }
  dotimes(i, N)
    if (p / b[i] % 2 == 0) {
      wint(0);
      return 0;
    }
  wint((M / p + 1) / 2);
  return 0;
}
