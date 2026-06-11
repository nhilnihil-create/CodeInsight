#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	priority_queue<ll> p;
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		p.push(a);
	}
	for (ll i = 0; i < m; i++) {
		ll tmp = p.top();
		tmp /= 2LL;
		p.pop();
		p.push(tmp);
	}
	ll ans = 0;
	while (!p.empty()) {
		ans += p.top();
		p.pop();
	}
	cout << ans << endl;
	return 0;
}