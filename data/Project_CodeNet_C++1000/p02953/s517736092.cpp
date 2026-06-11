#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = n-1; i >= 1; i--) {
		if (h[i - 1] > h[i]) h[i - 1]--;
	}
	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (!(h[i - 1] <= h[i])) {
			ok = false;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}