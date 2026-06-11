#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
	int a, b, h, m;
	cin >> a >> b >> h >> m;
	double hh = double(60 * h + m) / 720 * 2 * PI;
  	double mm = double(m) / 60 * 2 * PI;
  	double dd = abs(hh - mm);
	double ans = double(a * a + b * b) - 2 * a * b * cos(dd);
	ans = sqrt(ans);
	printf("%.15f", ans);
}
