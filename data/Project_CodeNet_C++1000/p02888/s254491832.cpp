#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int c = a[i] + a[j];
			int ind = lower_bound(a.begin(), a.end(), c) - a.begin();
			ans += ind - j - 1;
		}
	}
	cout << ans << '\n';
}