#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	vector<ll> num;
	rep(k, 2) {
		n -= (ll)k;
		if (n != 1) num.push_back(n);
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				num.push_back(i);
				if (i * i != n) num.push_back(n / i);
			}
		}
		n += k;
	}
	for (ll i : num) {
		ll a = n;
		while(a % i == 0) a /= i;
		if (a % i == 1) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
