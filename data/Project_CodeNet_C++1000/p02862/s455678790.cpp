#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define forep(i, k, n) for (int i = k; i < n; i++)
const int MAX = 2000000;
const ll MOD = 1000000007;

vector<ll> fac(MAX), finv(MAX), inv(MAX);
void comb_init()
{
  fac.at(0) = fac.at(1) = 1;
  finv.at(0) = finv.at(1) = 1;
  inv.at(1) = 1;
  forep(i, 2, MAX)
  {
    fac.at(i) = fac.at(i - 1) * i % MOD;
    inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
  }
}

ll comb(int n, int k)
{
  if (n < k)
  {
    return 0;
  }
  if (n < 0 || k < 0)
  {
    return 0;
  }
  return fac.at(n) * (finv.at(k) * finv.at(n - k) % MOD) % MOD;
}

int main()
{
  comb_init();
  int x, y;
  cin >> x >> y;
  if ((x + y) % 3 != 0)
  {
    cout << 0 << endl;
    return 0;
  }
  int a = y - (x + y) / 3, b = x - (x + y) / 3;
  cout << comb(a + b, a) << endl;
}