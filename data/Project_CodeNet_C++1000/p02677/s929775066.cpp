#include<iostream>
#include<cmath>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b, h, m;
	cin >> a >> b >> h >> m;

	long double rad, rad_a, rad_b;
	rad_a = h * 30 + m * 0.5;
	rad_b = m * 6;
	rad = abs(rad_a - rad_b);
	if (rad > 180) rad = 360 - rad;
	rad = M_PI * rad / 180;

	long double ans;
	ans = pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(rad);
	ans = sqrt(ans);

	cout << fixed << setprecision(20) << ans;
	return 0;
}