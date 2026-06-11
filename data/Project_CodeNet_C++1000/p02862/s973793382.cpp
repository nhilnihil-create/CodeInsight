#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr int MAX = 1000100;

ll x, y;
long fac[MAX], inv[MAX], finv[MAX];
void init()
{
    fac[0] = inv[0] = finv[0] = 1;
    fac[1] = inv[1] = finv[1] = 1;
    for (int i = 2; i < MAX; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long C(int n, int k)
{
    if (n < 0 || k < 0 || n < k)
        return 0;
    return (fac[n] * finv[n - k] % MOD) * finv[k] % MOD;
}

int main()
{
  cin >> x >> y;
  // a + b * 2 == x && a * 2 + b == y
  // 2 * (x - b * 2) + b == y
  // -3 * b == y - 2 * x
  // b == (2 * x - y) / 3
  // a == (2 * y - x) / 3
  init();
  if ((2 * x - y) % 3 == 0 && (2 * y - x) % 3 == 0) {
    ll a = (2 * x - y) / 3;
    ll b = (2 * y - x) / 3;
    cout << C(a + b, a);
  } else {
    cout << 0;
  }
  return 0;
}