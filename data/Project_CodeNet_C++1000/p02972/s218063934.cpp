#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
ll test[345678];
map<ll, ll> res;
void prime_factor(ll n) {
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			++res[i];
			if (i != n / i) { ++res[n / i]; }
		}
	}
}
signed main() {
	ll n, a = 0; cin >> n;
	vector<ll>ans;
	for (int h = 1; h <= n; h++) {
		cin >> test[h];
	}
	for (int h = n; h > 0; h--) {
		if ((res[h] + test[h]) % 2 == 1) { prime_factor(h); ans.push_back(h); a++; }
	}
	reverse(ans.begin(), ans.end());
	cout << a << endl;
	for (int h = 0; h < a; h++) {
		cout << ans[h] << endl;
	}
	return 0;
}