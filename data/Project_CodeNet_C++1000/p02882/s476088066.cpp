#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld PI = 3.14159265358979;
ld a, b, x;

bool check(ld ang) {
	ang = ang * PI / 180.0;
	ld s = b / tan(ang);

	ld area = b * s / 2.0;
	if (s > a) {
		ld sf = (s - a) / s;
		area -= area * sf * sf;
	}

	return area * a >= x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> x;

	ld l = 0;
	ld r = 90;

	ld ans = 0;
	for (int i = 0; i < 400; i++) {
		ld m = (l + r) / 2;
		if (check(m)) {
			ans = m;
			l = m;
		}
		else {
			r = m;
		}
	}

	cout << fixed << setprecision(10);
	cout << ans << '\n';
}
