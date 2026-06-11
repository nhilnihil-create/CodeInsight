#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	ll n, p;
	ll ans = 0;
	cin >> n >> p;
	string s;
	cin >> s;

	if (p == 2 || p == 5) {
		rep(i, n) {
			if ((s[i] - '0') % p == 0)ans += i + 1;
		}
		cout << ans << endl;
		return 0;
	}
	else {
		vector<ll> sum(n + 1);
		vector<ll> c(p);
		ll buf = 1;
		for (int i = n - 1; i >= 0; i--) {
			sum[i] = (sum[i + 1] + (s[i] - '0') * buf % p) % p;
			buf *= 10;
			buf %= p;
		}
		for (int i = n; i >= 0; i--) {
			ans += c[sum[i]];
			c[sum[i]]++;
		}
	}
	cout << ans << endl;
	return 0;
}
