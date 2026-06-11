#include <bits/stdc++.h>
using namespace std;
long long n;

int main() {
	cin >> n;

	long long ans = LLONG_MAX;
	for (long long x = 1; x * x <= n; x++) {
		if (n % x) continue;
		long long can = x + n / x;
		ans = min(ans, can);
	}

	cout << ans - 2 << '\n';

	return 0;
}
