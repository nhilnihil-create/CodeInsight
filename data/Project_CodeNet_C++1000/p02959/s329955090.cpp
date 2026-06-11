#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1), b(n);
	for (int i = 0; i < n + 1; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			ans += a[i];
			b[i] -= a[i];
			if (a[i + 1] < b[i]) {
				ans += a[i + 1];
				a[i + 1] = 0;
			} else {
				ans += b[i];
				a[i + 1] -= b[i];
			}
		} else {
			ans += b[i];
			a[i] -= b[i];
		}
	}
	cout << ans << '\n';
}
