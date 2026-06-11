#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

long long pow2(long long n) {
	return (1ll << n) % MOD;
}

int main() {
	int n;
	cin >> n;
	long long one[60] = {0};
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		for (int j = 0; a != 0; j++) {
			if (a & 1) one[j]++;
			a >>= 1;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 60; i++) {
		long long x = one[i] * (n-one[i]) % MOD;
		ans = mod(ans + pow2(i) * x % MOD);
	}
	cout << ans << endl;
	return 0;
}