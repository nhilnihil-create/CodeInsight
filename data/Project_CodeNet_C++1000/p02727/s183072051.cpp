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

	// guard
	p.push_back(0);
	q.push_back(0);
	r.push_back(0);

	int x = 0, y = 0, z = 0;
	ll ans = 0;
	while (x + y + z < X + Y) {
		ll red = p[x]; if (x >= X) red = 0;
		ll green = q[y]; if (y >= Y) green = 0;
		ll cless = r[z];
		
		ll eat = max(red, green); eat = max(eat, cless);
		if (eat == red) {
			ans += red; ++x;
		} else if (eat == green) {
			ans += green; ++y;
		} else {
			ans += cless; ++z;
		}
	}

	cout << ans << endl;

	return 0;
}
