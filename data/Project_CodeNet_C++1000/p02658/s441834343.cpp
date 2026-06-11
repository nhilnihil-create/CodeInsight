#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == 0) {
		cout << 0 << endl;
		return 0;
	}
	const ll u = 1000000000000000000LL;
	ll prod = 1;
	for (int i = 0; i < n; i++) {
		if (prod <= u / a[i]) {
			prod *= a[i];
		}
		else {
			prod = -1;
			break;
		}
	}
	cout << prod << endl;
	return 0;
}