#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

void solve_test() {
	int n;
	cin >> n;
	vector<LL> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int sum = 0;
	for (int i = 0; i < 60; i++) {
		int zero = 0;
		for (int j = 0; j < n; j++)
			if ((a[j] & (1LL << i)) == 0)
				zero++;
		int one = n - zero;
		sum = (sum + (1LL << i) % MOD * one % MOD * zero % MOD) % MOD;
	}
	cout << sum << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
