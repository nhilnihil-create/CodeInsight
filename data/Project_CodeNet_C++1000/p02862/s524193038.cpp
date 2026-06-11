#include <bits/stdc++.h>

using namespace std;

vector<long long> fac;
vector<long long> fac_inv;
vector<long long> inv;

void init_combination(long long n, long long mod)
{
	fac.resize(n+1);
	fac_inv.resize(n+1);
	inv.resize(n+1);
	fac[0] = 1;
	fac[1] = 1;
	fac_inv[0] = 1;
	fac_inv[1] = 1;
	inv[1] = 1;
	for (long long i = 2; i <= n; i++) {
		fac[i] = fac[i-1]*i%mod;
		inv[i] = mod - (inv[mod%i] * (mod / i)) % mod;
		fac_inv[i] = fac_inv[i-1] * inv[i] % mod;
	}
}

long long modcomb(long long n, long long r, long long mod)
{
	if (n < r)
		return 0;
	long long result = fac[n]%mod;
	result *= (fac_inv[r] * fac_inv[n-r]) % mod;
	result %= mod;
	return result;
}
int main(void)
{
	const long long p = (long long)1e9+7;
	int x, y;
	cin >> x >> y;
	if ((2*y-x)%3 != 0 || (2*x-y)%3 != 0) {
		cout << 0 << endl;
		return 0;
	}

	int a = (2*y-x)/3;
	int b = (2*x-y)/3;
	if (a < 0 || b < 0) {
		cout << 0 << endl;
		return 0;
	}

	init_combination(a+b, p);
	cout << modcomb(a+b, a, p) << endl;

	return 0;
}