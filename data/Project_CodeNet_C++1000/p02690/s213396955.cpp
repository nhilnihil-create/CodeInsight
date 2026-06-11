#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int n, a, b;
	cin >> n;
	for (ll x =-200; x <= 200; x++) {
		for (ll y = -200; y <= 200; y++) {
			ll c = x * x * x * x * x - y * y * y * y * y;
			if (n != c) continue;
			a = (int)x;
			b = (int)y;
		}
	}
	cout << a << ' ' << b << endl;
	return 0;
}
// a^5 = n + b^5