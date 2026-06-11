#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	vector<long long> prefix(n + 1), suffix(n + 1);
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + a[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		suffix[i] = suffix[i + 1] + a[i];
	}
	long long ans = LLONG_MAX;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, abs(suffix[i] - prefix[i]));
	}
	cout << ans;
}

