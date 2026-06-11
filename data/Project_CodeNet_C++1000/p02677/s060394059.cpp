#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 998244353

using namespace std;
using ll = long long;

int main() {
	double a, b,  h, m;
	cin >> a >> b >> h >> m;
	h = 30 * h + m / 2;
	m = m * 6;
	double rad = max(h, m) - min(h, m);
	if (rad > 180) rad = 360 - rad;
	rad = acos(-1) * rad / 180;
	double ans = a*a  + b*b - 2*a*b*cos(rad);
	ans = sqrt(ans);
	printf("%.10f\n", ans);
	return 0;
}
