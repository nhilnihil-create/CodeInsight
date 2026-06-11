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

// Returns the gcd while setting x and y so that a x + b y = gcd
int euclid(int a, int b, int& x, int& y) {
  if (a < b) {
    int d = euclid(b, a, x, y);
    int t = x;
    x = y;
    y = t;
    return d;
  }
  int m[2][2] = { { 1, 0 }, { 0, 1 } };
  while (b > 0) {
    int q = a / b, r = a % b;
    int n[2][2] = { { 0, 1 }, { 1, -q } }, l[2][2] = { { 0, 0 }, { 0, 0 } };
    dotimes(i, 2)
      dotimes(j, 2)
      dotimes(k, 2)
      l[i][j] += n[i][k] * m[k][j];
    dotimes(i, 2)
      dotimes(j, 2)
      m[i][j] = l[i][j];
    a = b;
    b = r;
  }
  x = m[0][0];
  y = m[0][1];
  return a;
}

inline int euclid(int a, int b, int& x) {
  int y;
  return euclid(a, b, x, y);
}

inline int euclid(int a, int b) {
  int x;
  return euclid(a, b, x);
}

int modinv(int a, int p) {
  int x;
  euclid(a, p, x);
  int r = x % p;
  return r < 0 ? r + p : r;
}

int modpow(int m, int n, int p) {
  int r = 1;
  while (n) {
    if (n & 1)
      r = r * m % p;
    m = m * m % p;
    n >>= 1;
  }
  return r;
}

int modbinom(int n, int k, int p) {
  if (n - k < k)
    k = n - k;
  int numer = 1, denom = 1;
  dotimes(i, k) {
    numer = numer * (n-i) % p;
    denom = denom * (k-i) % p;
  }
  return numer * modinv(denom, p) % p;
}

signed main() {
  int X = rint();
  int Y = rint();
  if (!((X + Y) % 3 == 0 && Y <= X * 2 && X <= Y * 2)) {
    wint(0);
    return 0;
  }
  int a = (2 * X - Y) / 3, b = X - 2 * a;
  wint(modbinom(a + b, a, 1'000'000'007));
  return 0;
}
