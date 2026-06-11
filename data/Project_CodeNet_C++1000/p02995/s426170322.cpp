#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

ll a, b;

ll number(ll divide) {
  return b / divide - (a - 1) / divide;
}

int main()
{
  ll c, d, lcm;
  cin >> a >> b >> c >> d;

  lcm = (c / __gcd(c, d)) * d;
  cout << b - a + 1 - number(c) - number(d) + number(lcm) << endl;

  return 0;
}
