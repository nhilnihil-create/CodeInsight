#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, k, a[N], b[N];

bool check(long long val) {
	long long op = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) continue;
		op += max(0LL, (long long) a[i] - (long long) val / b[i]);
	}

	return op <= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n, greater<int>());

	long long l = 0;
	long long r = 1e13;
	
	long long ans = LLONG_MAX;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (check(m)) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
