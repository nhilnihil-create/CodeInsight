#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n), num(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		num[a[i]]++;
	}
	ll sum = 0;
	for (ll i = 0; i <= n; i++) {
		sum += num[i] * (num[i] - 1) / 2;
	}
	for (ll i = 0; i < n; i++) {
		ll tmp = 0;
		tmp += sum;
		tmp -= num[a[i]] * (num[a[i]] - 1) / 2;
		tmp += (num[a[i]] - 1) * (num[a[i]] - 2) / 2;
		cout << tmp << endl;
	}
	return 0;
}