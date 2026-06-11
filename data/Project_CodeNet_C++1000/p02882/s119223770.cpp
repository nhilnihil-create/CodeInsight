#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cout << fixed << setprecision(15);
	double a, b, x;
	cin >> a >> b >> x;
	x = x / a;
	double ans;
	if (x <= a * b * 0.5) {
		double y = x * 2.0 / b;
		ans = atan(b / y);
		ans = ans * 180.0 / 3.14159265358979;
	}
	else {
		double y = (a * b - x) * 2.0 / a;
		ans = atan(y / a);
		ans = ans * 180.0 / 3.14159265358979;
	}
	cout << ans << endl;
}