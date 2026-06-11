#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

double a, b, h, m;

int main()
{
//	ios::sync_with_stdio(false), cin.tie(0);
	
//	cin >> a >> b >> h >> m;
	scanf("%lf%lf%lf%lf", &a, &b, &h, &m);
	
	double ang = fabs(h / 12 * 360 + m / 60 * 30 - m / 60 * 360);
	ang = min(ang, 360 - ang);
//	cout << ang << endl;
	
//	if (fabs(ang - 180) < 1e-9) cout << a + b << '\n';
//	else cout << sqrt(a * a + b * b - 2 * a * b * cos(ang * PI / 180)) << '\n';
	if (fabs(ang - 180) < 1e-9) printf("%.12lf\n", a + b);
	else printf("%.12lf\n", sqrt(a * a + b * b - 2 * a * b * cos(ang * PI / 180)));
	
	return 0;
}