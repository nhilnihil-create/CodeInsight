#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nm = 2e5;
int n, smax, smin, dmax, dmin;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, s, d;
		cin >> x >> y;
		s = x + y;
		d = x - y;
		if (!i) {
			smax = s;
			smin = s;
			dmax = d;
			dmin = d;
		} else {
			smax = max(smax, s);
			smin = min(smin, s);
			dmax = max(dmax, d);
			dmin = min(dmin, d);
		}
	}
	cout << max(smax - smin, dmax - dmin) << endl;
}
