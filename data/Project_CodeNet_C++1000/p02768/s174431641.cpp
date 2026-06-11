#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < (n); i++)
using namespace std;
const int mod = 1000000007;

long long f(long long n)
{
	if (n == 0) return 1;
	long long x = f(n / 2);
	x *= x;
	if (n % 2 != 0) x *= 2;
	return x % mod;
}

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
long long nCr(long long n, long long r) {
  long long x = 1;
  long long y  = 1;
  for (long long i = 1; i <= r; ++i ) {
    x *= (n-i+1);
    y *= i;
	x %= mod;
	y %= mod;
  }
  return x * calc(y, mod - 2, mod) % mod;
}

signed main(void)
{
	long long n, a, b;
	long long sum;

	cin >> n >> a >> b;
	sum = f(n);
	sum %= mod;
	sum -= 1;
	sum %= mod;
	sum -= nCr(n, a); 
	sum %= mod;
	sum -= nCr(n, b);
	sum %= mod;
	while (sum < 0) sum += mod;
	cout << sum << endl;
	return 0;
}
