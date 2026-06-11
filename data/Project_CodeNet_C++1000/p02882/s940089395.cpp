#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b, x; cin >> a >> b >> x;
	int V = a * a * b;	
	double ans;
	if (V < 2 * x) {
		double tmp = (double)2 * (a * a * b - x) / (a * a * a);
		tmp = atan(tmp);
		ans = tmp * 180 / M_PI;
	}
	else { // 2 * x <= V 
		double tmp = (double)(a * b * b) / (2 * x);
		tmp = atan(tmp);
		ans = tmp * 180 / M_PI;
	}

	double Sx = (double)x / a;
	cout << fixed << setprecision(11) << ans << endl;
	return 0;
}