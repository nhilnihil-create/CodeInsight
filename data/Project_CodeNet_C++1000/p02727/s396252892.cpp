#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
	vector<ll> h;
	vector<ll> p(a);
	for (int i = 0; i < a; i++) {
		cin >> p[i];		
	}
	sort(p.rbegin(), p.rend());
	for (int i = 0; i < x; i++) {
		h.push_back(p[i]);
	}
	vector<ll> q(b);
	for (int i = 0; i < b; i++) {
		cin >> q[i];
	}
	sort(q.rbegin(), q.rend());
	for (int i = 0; i < y; i++) {
		h.push_back(q[i]);
	}
	for (int i = 0; i < c; i++) {
		int r; cin >> r;
		h.push_back(r);
	}	
	sort(h.rbegin(), h.rend());
	ll ans = 0;
	for (int i = 0; i < x + y; i++) {
		ans += h[i];
	}
	cout << ans << endl;
	return 0;
}