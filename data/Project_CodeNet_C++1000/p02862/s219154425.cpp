#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1000000;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

long long inverse[MAX+1];
long long factorial[MAX+1];
long long factorial_inverse[MAX+1];

void calc(int n) {
	inverse[1] = 1;
	factorial[0] = factorial[1] = 1;
	factorial_inverse[0] = factorial_inverse[1] = 1;
	for (int i = 2; i <= n; i++) {
		inverse[i] = MOD - inverse[MOD%i] * (MOD/i) % MOD;
		factorial[i] = i * factorial[i-1] % MOD;
		factorial_inverse[i] = inverse[i] * factorial_inverse[i-1] % MOD;
	}
}

long long comb(long long n, long long k) {
	return factorial[n] * (factorial_inverse[k] * factorial_inverse[n-k] % MOD) % MOD;
}

int main() {
	int x, y;
	cin >> x >> y;
	if ((x+y)%3 != 0 || y > 2*x || 2*y < x) {
		cout << 0 << endl;
		return 0;
	}
	int n = (x+y) / 3;
	int cx = x - n;
	calc(n);
	long long ans = comb(n, cx);
	cout << ans << endl;
	return 0;
}