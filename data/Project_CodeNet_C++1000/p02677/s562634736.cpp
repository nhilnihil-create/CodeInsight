#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

#define PI 3.1415926535897932384626433832795028841971

signed main(void)
{
	int a, b, h, m; cin >> a >> b >> h >> m;
	h %= 12;
	double t;
	t = ((60*h+m)/2.0 - m*6) * PI/180;
	double c;
	c = a*a + b*b - 2*a*b*cosf64(t);
	c = sqrt(c);
	cout << std::fixed << std::setprecision(30) << c << endl;
}
