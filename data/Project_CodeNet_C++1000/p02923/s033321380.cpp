#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	long long prev = 0;
	long long count = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= prev) count++;
		else count = 0;
		ans = max(ans, count);
		prev = a[i];
	}
	cout << ans << '\n';
	return 0;
}
