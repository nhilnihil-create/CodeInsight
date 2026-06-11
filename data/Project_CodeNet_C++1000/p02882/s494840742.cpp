#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int a, b, x;
	cin >> a >> b >> x;
	if (2*x <= a*a*b) {
		long double c = 2.0*(long double)x / (a*b);
		long double sqd = b*b+c*c;
		long double d = sqrt(sqd);
		long double cos_theta = (c*c + d*d - b*b)/(2*c*d);
		long double theta = acos(cos_theta);
		printf("%20.20Lf\n", 180.0 * theta / M_PI);
	} else {
		long long tmp = a*a*b-x;
		long double e = 2.0*(long double)tmp / (a*a);
		long double sqf = a*a+e*e;
		long double f = sqrt(sqf);
		long double cos_theta = (a*a + f*f - e*e)/(2.0*a*f);
		long double theta = acos(cos_theta);
		printf("%20.20Lf\n", 180.0 * theta / M_PI);
	}
	return 0;
}