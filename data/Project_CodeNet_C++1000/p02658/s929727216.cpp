#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 998244353;

const int LIMIT_SQ = 1000 * 1000 * 1000;
const LL LIMIT = (LL) LIMIT_SQ * LIMIT_SQ;

void solve_test() {
	int n;
	cin >> n;
	vector<LL> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	bool has_zero = false;
	for (int i = 0; i < n; i++) if (a[i] == 0) has_zero = true;
	if (has_zero) {
		cout << "0\n";
		return;
	}

	LL prod = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > LIMIT / prod) {
			cout << "-1\n";
			return;
		}
		prod *= a[i];
	}
	cout << prod << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
