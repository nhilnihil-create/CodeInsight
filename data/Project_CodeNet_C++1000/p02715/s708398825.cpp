#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
const int64_t MAXN = 100010;

int64_t P[MAXN];
int64_t pow_mod(int64_t x, int64_t n)
{
  int64_t res = 1;
  if (n > 0)
  {
    res = pow_mod(x, n / 2);
    if (n % 2 == 0)
      res = (res * res) % MOD;
    else
      res = (((res * res) % MOD) * x) % MOD;
  }
  return res;
}

int main()
{
  int64_t N, K, ans = 0;
  cin >> N >> K;
  for (int64_t i = 1; i <= K; i++)
  {
    P[i] = pow_mod(i, N);
  }
  vector<int64_t> v(K + 1, 0);
  for (int64_t k = K; k >= 1; k--)
  {
    v[k] = P[K / k];
    for (int64_t i = 2; i * k <= K; i++)
    {
      v[k] -= v[i * k];
    }
    (ans += (k * v[k]) % MOD) %= MOD;
  }
  cout << (ans + MOD) % MOD << endl;
}