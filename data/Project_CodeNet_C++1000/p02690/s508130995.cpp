#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll x; cin >> x;	
	const ll p = 1000;
	for (ll i = -p; i <= p; i++) {
		for (ll j = -p; j <= p; j++) {
			ll a = i * i * i * i * i;
			ll b = j * j * j * j * j;
			if (a - b == x) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	return 0;
}