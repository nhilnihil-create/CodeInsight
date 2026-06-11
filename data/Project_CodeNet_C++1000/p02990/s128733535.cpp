#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;

int64_t modinv(int64_t a, int64_t m)
{
  int64_t b = m, u = 1, v = 0;
  while (b)
  {
    int64_t t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

int64_t nCk(int64_t n, int64_t k)
{
  int64_t res = 1;
  for (int64_t i = 1; i <= k; i++)
  {
    res = (((res * (n - i + 1)) % MOD) * modinv(i, MOD)) % MOD;
  }
  return res;
}

int main()
{
  int64_t N, K;
  cin >> N >> K;
  for (int64_t i = 1; i <= K; i++)
  {
    if (N - K - i + 1 < 0)
    {
      cout << 0 << endl;
      continue;
    }
    int64_t a = nCk(K - 1, i - 1) % MOD;
    a = (a * nCk(N - K + 1, N - K - i + 1)) % MOD;
    cout << a % MOD << endl;
  }
}