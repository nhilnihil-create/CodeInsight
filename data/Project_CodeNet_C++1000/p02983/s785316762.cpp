#include "bits/stdc++.h"
using namespace std;

//50 
typedef long long ll;

int main() {
	ll l, r;
    cin >> l >> r;
    if (r / 2019 > l / 2019) {
		cout << 0;
	}else {
		ll minn = 1e18 + 10000;
		for (ll i = l; i < r; ++i) {
			for (ll j = i + 1; j <= r; ++j) {
				minn = min(minn,(i * j) % 2019);
			}
		} 
		cout << minn;
	}
}
	
