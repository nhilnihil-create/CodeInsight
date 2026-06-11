#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	long long n, k;
	cin >> n >> k;
	long long ma = n, mi = 0;
	long long ans = 0;
	for (int i = 1; i <= n+1; i++) {
		if (i >= k) ans = mod(ans + ma - mi + 1);
		ma = mod(ma + n - i);
		mi = mod(mi + i);
	}
	cout << ans << endl;
	return 0;
}