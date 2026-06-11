#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	ll l, r;
	cin >> l >> r;
	ll mn = 1e9;
	for(ll i = l; i <= r; i++) {
		for(ll j = i + 1; j <= r; j++) {
			mn = min(mn, (i * j) % 2019);
			if(mn == 0) {
				cout << mn;
				return;
			}
		}
	}
	cout << mn;


	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}