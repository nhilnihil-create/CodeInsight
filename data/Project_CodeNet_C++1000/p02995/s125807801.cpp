#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(void) {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x, y, z, lc = lcm(c, d);
  x = b / c;
  y = b / d;
  z = b / lc;
  ll ans = x + y - z, ans2;
  x = (a - 1) / c;
  y = (a - 1) / d;
  z = (a - 1) / lc;
  ans2 = x + y - z;
  a--;
  cout << b - ans + ans2 - a << '\n';
  return 0;
}