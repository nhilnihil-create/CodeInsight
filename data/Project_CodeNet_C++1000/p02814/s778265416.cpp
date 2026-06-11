#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  ll N, M;
  cin >> N >> M;
  ll lcm = 1;
  ll gcd = 0;
  rep(i, N)
  {
    ll now;
    cin >> now;
    now /= 2;
    lcm = now * lcm / __gcd(now, lcm);
    gcd = __gcd(now, gcd);
  }
  if (lcm / gcd % 2 == 0)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << M / lcm - M / (2 * lcm) << endl;
  }
}