#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	vector<ll> q(n+1);
	for (ll i = 0; i < n; ++i)
	{
		ll p; cin >> p;
		q[p] = i+1;
	}

	multiset<ll> s;
	s.insert(0);
	s.insert(0);
	s.insert(n+1);
	s.insert(n+1);
	s.insert(q[n]);
	ll ans = 0;

	for (ll i = n-1; i > 0; --i)
	{
		auto loc = s.lower_bound(q[i]);
		for (ll j = 0; j < 2; ++j) --loc; auto w = *loc;
		for (ll j = 0; j < 1; ++j) ++loc; auto x = *loc;
		for (ll j = 0; j < 1; ++j) ++loc; auto y = *loc;
		for (ll j = 0; j < 1; ++j) ++loc; auto z = *loc;
		//cout << w << " " << x << " " << q[i] << " " << y << " " << z << endl; 
		ans += i * ((x-w) * (y-q[i]) + (q[i]-x) * (z-y));
		s.insert(q[i]);
	}

	cout << ans << endl;
	return 0;
}