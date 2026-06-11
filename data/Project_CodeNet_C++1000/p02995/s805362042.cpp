#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
  if (y == 0)
  {
    return x;
  }
  return gcd(y, x % y);
}

ll lcm(ll x, ll y)
{
  return x / gcd(x, y) * y;
}

ll solve(ll x, ll a, ll b)
{
  return x - (x / a + x / b - x / lcm(a, b));
}

int main()
{
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll s, t, st, num;

  cout << solve(b, c, d) - solve(a - 1, c, d) << endl;
}
