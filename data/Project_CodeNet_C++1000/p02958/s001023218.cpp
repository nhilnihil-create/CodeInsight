#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ll p;
		cin >> p;
		if (p != i + 1)++ans;
	}
	if (ans <= 2)cout << "YES" << endl;
	else cout << "NO" << endl;
}
