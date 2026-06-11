#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, x;
	cin >> n >> x;

	int d[n+1];
	d[0] = 0;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		d[i+1] = d[i] + a;
	}

	for (int i = 0; i <= n; i++) {
		if (d[i] <= x) { ans++; }
	}
	cout << ans;
	return 0;
}