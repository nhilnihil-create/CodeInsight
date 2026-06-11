#include <bits/stdc++.h>

using namespace std;
long long modpow(long long x, long long y, long long mod)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			result %= mod;
			y -= 1;
		}	
		x *= x;
		x %= mod;
		y /= 2;
	}
	return result;
}
int main(void)
{
	const long long p = (long long)1e9+7;
	int n;
	cin >> n;
	vector<long long> zeros(60, 0);
	vector<long long> ones(60, 0);

	for (int i = 0; i < n; i++) {
		uint64_t a;
		cin >> a;
		for (int j = 0; j < 60; j++) {
			if (((a>>j)&1) == 1)
				ones[j]++;
			else
				zeros[j]++;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 60; i++) {
		ans += (((zeros[i]*ones[i])%p)* modpow(2, i, p))%p;
		ans %= p;
	}
	cout << ans << endl;
	return 0;
}