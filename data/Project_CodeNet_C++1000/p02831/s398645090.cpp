#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(void) {
  ll a, b;
  cin >> a >> b;
  ll ans = lcm(a, b);
  cout << ans << endl;
  return 0;
}
