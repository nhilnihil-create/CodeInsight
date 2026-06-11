#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void solve_test() {
	LL n;
	cin >> n;

	int ops = 0;
	for (LL i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}

			int j = 1;
			while (cnt >= j) {
				cnt -= j;
				j++;
				ops++;
			}
		}
	}
	if (n > 1)
		ops++;

	cout << ops << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
