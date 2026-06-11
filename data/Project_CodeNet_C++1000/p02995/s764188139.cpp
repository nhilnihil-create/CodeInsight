#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

double eta = 1e-10;

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

ll div_and_ceil(ll a, ll b) {
  if (0 < a - a / b * b)
    return a / b + 1;
  else
    return a / b;
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll e1 = ll(b / c) - div_and_ceil(a, c) + 1;
  ll e2 = ll(b / d) - div_and_ceil(a, d) + 1;
  ll e3 = ll(b / lcm(d, c)) - div_and_ceil(a, lcm(d, c)) + 1;
  cout << b - a + 1 - (e1 + e2 - e3) << endl;
}