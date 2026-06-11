#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef long long ll;


int main() {
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;

	vector<ll> p(A), q(B), r(C);
	for (int i = 0; i < A; ++i) cin >> p[i];
	for (int i = 0; i < B; ++i) cin >> q[i];
	for (int i = 0; i < C; ++i) cin >> r[i];

	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.rbegin(), r.rend());

	p.resize(X);
	q.resize(Y);

	// guard
	p.push_back(0);
	q.push_back(0);
	r.push_back(0);

	int x = 0, y = 0, z = 0, w = 0;
	ll ans = 0;
	while (X + Y) {
		ll red = p[x]; if (!X) red = 0;
		ll green = q[y]; if (!Y) green = 0;
		ll cless = r[z];
		
		ll mx = max(red, green); mx = max(mx, cless);
		if (mx == red) {
			ans += red; ++x; --X;
		} else if (mx == green) {
			ans += green; ++y; --Y;
		} else {
			ll a = p[x + X - 1]; if (!X) a = 1e10;
			ll b = q[y + Y - 1]; if (!Y) b = 1e10;

			ans += cless; ++z;
			
			if (a < b) --X;
			else --Y;
		}
	}

	cout << ans << endl;

	return 0;
}
