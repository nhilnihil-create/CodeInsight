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
const long long p = 1e9+7;
int main(void)
{
	long long n, k;
	cin >> n >> k;
	init_combination(max(k-1, n-k+1), p);
	for (long long i = 1; i <= k; i++) {
		long long ans = modcomb(k-1, i-1, p);
		ans *= modcomb(n-k+1, i, p);
		ans %= p;
		cout << ans << endl;
	}
	return 0;
}