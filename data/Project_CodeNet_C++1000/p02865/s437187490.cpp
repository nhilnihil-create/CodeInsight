#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	if (n % 2) {
		cout << n/2;
	} else {
		cout << n/2 - 1;
	}

	return 0;
}
