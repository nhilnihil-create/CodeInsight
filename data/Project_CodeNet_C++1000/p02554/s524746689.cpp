#include <bits/stdc++.h>
using namespace std;

const long long int MOD = pow(10, 9) + 7;

int main(void) {

	int N;
	cin >> N;
	long long int a = 1, b = 1, c = 1, ans;
	for (int i = 0; i < N; i++) {
		a *= 10;
		a %= MOD;
		b *= 8;
		b %= MOD;
		c *= 9;
		c %= MOD;
	}
	ans = (a + b - 2 * c) % MOD;
	if (ans < 0) ans += MOD;
	cout << ans << endl;
}