#include <bits/stdc++.h>
using namespace std;

long long a[1 << 20], R[1 << 20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i];
	if (n == 0) {
		if (a[0] == 1) cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	R[0] = 1;
	for (int i = 1; i <= n; i++) {
		R[i] = (R[i - 1] - a[i - 1]) * 2;
		if (R[i] > 1LL << 60) {
			for (int j = i + 1; j <= n; j++) R[j] = R[i];
			break;
		}
	}
	long long ans = 0;
	for (int i = n; i >= 0; i--) {
		if (a[i] > R[i]) {
			cout << -1 << endl;
			return 0;
		}
		ans += a[i];
		if (i) {
			if (a[i - 1] + (a[i] + 1) / 2 > R[i - 1]) {
				cout << -1 << endl;
				return 0;
			}
			a[i - 1] = min(a[i - 1] + a[i], R[i - 1]);
		}
	}
	cout << ans << endl;
	return 0;
}

