#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x;
	cin >> x;
	for (ll i=-1000; i<=1000; i++) {
		for (ll j=-1000; j<=1000; j++) {
			ll val1 = i*i*i*i*i;
			ll val2 = j*j*j*j*j;
			if (val1-val2==x) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}