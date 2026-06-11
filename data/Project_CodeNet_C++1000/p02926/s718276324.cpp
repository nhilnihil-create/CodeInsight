#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	tuple<double, double, double> t[2 * n];
	for(int i = 0; i < n; ++i) {
		double x, y; cin >> x >> y;
		double arg = atan2(y, x);
		t[i] = t[i + n] = make_tuple(arg, x, y);
	}
	sort(t, t + n);
	sort(t + n, t + 2 * n);
	// for(int i = 0; i < 2 * n; ++i) {
	// 	double _arg, x, y;
	// 	tie(_arg, x, y) = t[i];
	// 	cerr << _arg << " " << x << " " << y << endl;		
	// }
	double ans = 0;
	for(int l = 0; l < n; ++l) {
		for(int r = l; r <= 2 * n; ++r) {
			if(r - l > n) continue;
			double xsum = 0, ysum = 0;
			for(int i = l; i < r; ++i) {
				double _arg, x, y;
				tie(_arg, x, y) = t[i];
				xsum += x;
				ysum += y;
			}
			ans = max(ans, xsum * xsum + ysum * ysum);
		}
	}
	printf("%.15f\n", sqrt(ans));
	return 0;
}