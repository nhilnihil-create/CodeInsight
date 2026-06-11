#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll x = 0;
	ll cnt = n;
	while (true) {
		if (cnt % 2 == 1) x += a[cnt];
		else x -= a[cnt];
		cnt--;
		if (cnt == 0) break;
	}
	cout << x << " ";
	ll x_now;
	ll x_prev = x / 2;
	for (int i = 2; i <= n; i++) {
		x_now = a[i - 1] - x_prev;
		cout << 2 * x_now << " ";
		x_prev = x_now;
	}	 
	return 0;
}