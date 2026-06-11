#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int a, b, h, m;

long double Convert(long double degree)
{
	long double pi = 3.14159265359;
	return (degree * (pi / 180));
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> h >> m;
	long double degreeofhour = 0, degreeofminute = 0;
	if (h != 12)
		degreeofhour = (long double)0.5 * (h * (long double)60 + m);
	if (m != 60)
		degreeofminute = m * (long double)6;
	long double degreebetweentwohands = max(degreeofhour, degreeofminute) - min(degreeofhour, degreeofminute);
	degreebetweentwohands = min(360 - degreebetweentwohands, degreebetweentwohands);
	long double angleinrad = Convert(degreebetweentwohands);
	// long double finalangle = cal_cos(degreebetweentwohands);
	long double ans = sqrt(a * a + b * b - (2 * a * b * cos(angleinrad)));
	cout << fixed << setprecision(9) << ans;
	return 0;
}
//11-09-2020 09:39:01