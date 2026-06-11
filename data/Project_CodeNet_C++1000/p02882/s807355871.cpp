#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i = 0;i < (n); ++i)

int main() {
	long double a, b, x, pi;
	cin >> a >> b >> x;
	pi = acos(-1);
	long double ans;
	if (a *a* b >= 2 * x) {
		ans = atan(a * b * b / (2 * x));
		ans *= 180;
		ans /= pi;
			printf("%2.10llf\n", ans);
	}
	else {
		ans = atan((2 * a * a * b - 2 * x) / (a * a * a));
		ans *= 180;
		ans /= pi;
		printf("%2.10llf\n", ans);
	}

	return 0;
}