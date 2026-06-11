#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
	ll x, k, d;
	cin >> x >> k >> d;
	ll i, j;
	ll buf1, buf2;
	ll ans;
	if (x > 0) {
		if (x / d > k) {
			ans = x - k * d;
		}
		else {
			buf1 = x % d;
			if ((k - x / d) % 2 == 0)ans = buf1;
			else ans = abs(buf1 - d);
		}
	}
	else if(x < 0){
		if (-x / d > k) {
			ans = -x - k * d;
		}
		else {
			buf1 = -x % d;
			if ((k + x / d) % 2 == 0)ans = buf1;
			else ans =-buf1 + d;
		}
	}
	else {
		if (k % 2 == 0)ans = 0;
		else ans = d;
	}
	cout << ans << endl;
	return 0;
}