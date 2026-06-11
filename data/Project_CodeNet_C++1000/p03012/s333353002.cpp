#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int count = 0;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		count += a[i];
	}
	int count2 = 0;
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		count2 += a[i];
		count -= a[i];
		ans = min(ans, abs(count - count2));
	}
	cout << ans << '\n';
	return 0;
}
