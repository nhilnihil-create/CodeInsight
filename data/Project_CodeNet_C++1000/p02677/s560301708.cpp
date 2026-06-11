#include <bits/stdc++.h>
using namespace std;

/*
二つのなす角をthetaとすると、余弦定理より
ans = sqrt(a^2 + b^2 - 2 * a * b * cos(theta))

0からの角度は、
時針がH * 30 + M * 0.5
分針がM * 6
*/

int	main(void)
{
	int a, b, h, m;
	cin >> a >> b >> h >> m;
	double hour = (double)h * 30 + (double)m * 0.5;
	double minite = m * 6;
	double theta = hour - minite;
	while (theta < 0) theta += 360;
	while (theta > 360) theta -= 360;
	theta = min(theta, 360 - theta);
	cout << setprecision(15) << sqrt((double)a * a + (double)b * b - 2 * (double)a * b * cos(M_PI * theta / 180)) << endl;
	return (0);
}
