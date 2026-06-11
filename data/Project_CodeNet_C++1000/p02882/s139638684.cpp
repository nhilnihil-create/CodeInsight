#include <bits/stdc++.h>
using namespace std;

int	main()
{
	double a, b, x;
	cin >> a >> b >> x;
	x /= a;
	double result;
	if (x < 0.5 * a * b) {
		double c = 2 * x / b;
		result = atan(b / c);
	} else {
		double c = 2 * (b - x / a);
		result = atan(c / a);
	}
	result = result / M_PI * 180;
	cout << setprecision(10) << result << endl;
}
