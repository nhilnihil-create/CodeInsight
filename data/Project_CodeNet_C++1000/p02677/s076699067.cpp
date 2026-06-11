// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int h, m;
	cin >> h >> m;

	double x = h * 30 + m * 0.5;
	
	double y = m * 6;

	double pi = acos(-1);

	auto in_radians = [&](double degree) {
		return (degree * pi) / 180;
	};

	double ans = a*a + b*b - 2 * a * b * cos(in_radians(x-y));

	ans = sqrt(ans);

	cout << fixed << setprecision(10) << ans;

	return 0;
}
