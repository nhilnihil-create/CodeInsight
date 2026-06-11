#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] != a[j]) {
				for (int k = j + 1; k < n; ++k) {
					if (a[k] != a[j] && a[k] != a[i]) {
						ans += ((long long) a[i] + a[j] + a[k] > (long long) 2 * max(a[i], max(a[j], a[k])));
					}
				}
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}