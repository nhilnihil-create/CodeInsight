#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

const int mod = 1e9+7; 
long long calc(long long a, long long b, long long p)
{
	if (b == 0) return 1;
	if (b % 2 == 0)
	{
		long long d = calc(a, b / 2, p);
		return (d * d) % p;
	}
	else
		return (a * calc(a, b - 1, p)) % p;
}
long long nCr(long long n, long long r)
 {
  long long x = 1;
  long long y  = 1;
  for (long long i = 1; i <= r; ++i )
	 {
    x *= (n-i+1);
		x %= mod;
    y  *= i;
		y %= mod;
  }
  return x * calc(y, mod - 2, mod) % mod;
}
signed main(void)
{
	int n, k;
	ll ans;
	cin >> n >> k;
	ans = 0;
	for (int i = 1; i <= k; i++)
	{
		ans = nCr(n - k + 1, i);
		ans *= nCr(k - 1, i - 1);
		ans %= mod;
		cout << ans << endl;
	}
	return 0;
}
