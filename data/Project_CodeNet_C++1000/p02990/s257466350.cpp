#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int mod = 1000000007;
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
	if (r == 0) return 1;
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
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
	{
		ll ans;
		ans = nCr(n - k + 1, i) * nCr(k - 1, i - 1) % mod;
		cout << ans << endl;
	}
	return 0;
}
