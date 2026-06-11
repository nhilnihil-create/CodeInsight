#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	ll max_f = 0;
	ll max_s = 0;
	ll max_f_index;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (max_f <= a[i]) {
			max_s = max_f;
			max_f = a[i];
			max_f_index = i;			
		}
		else if (max_s <= a[i]) {
			max_s = a[i];
		}
	}
	for (ll i = 0; i < n; i++) {
		if (i == max_f_index) {
			cout << max_s << endl;
		}
		else {
			cout << max_f << endl;
		}
	}
	return 0;
}