#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	double n;
	cin >> n;
	double req = ceil(n / 1.08);
	if (floor(req * 1.08) == n) {
		cout << req;
	} else {
		cout << ":(";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
