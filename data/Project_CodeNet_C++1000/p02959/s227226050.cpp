#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> a(n + 1);
	vector<ll> b(n);
	for (int i = 0; i < n + 1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] <= a[i]) {
			ans += b[i];
			a[i] -= b[i];
			b[i] = 0;
		}
		else { // a[i] < b[i]
			ans += a[i];
			b[i] -= a[i];
			a[i] = 0;
			if (b[i] <= a[i + 1]) {
				ans += b[i];
				a[i + 1] -= b[i];
				b[i] = 0;
			}
			else {  // a[i + 1] < b[i]
				ans += a[i + 1];
				b[i] -= a[i + 1];
				a[i + 1] = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}