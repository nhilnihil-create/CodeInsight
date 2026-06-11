#include <bits/stdc++.h>
#define For(i, a, b) for(long long i = (a); i < (b); i++)
#define rep(i, n) for(long long i = 0; i <= (n); i++)
using namespace std;

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
  long long x = 1;
  long long y  = 1;
  for (long long i = 1; i <= r; ++i ) {
    x *= (n-i+1);
	x %= mod;
    y  *= i;
	y %= mod;
  }
  return x * calc(y, mod - 2, mod) % mod;
}

signed main(void)
{
	long long x, y, n, m, ans;

	cin >> x >> y;
	if ((x + y) % 3)
	{
		cout << "0" << endl;
		return 0;
	}
	n = (x + y) / 3;
	m = x - n;
	n -= m;
	if (n < 0 || m < 0)
	{
		cout << "0" << endl;
		return 0;
	}
	ans = nCr(n + m, m);
	cout << ans << endl;
	return 0;
}
