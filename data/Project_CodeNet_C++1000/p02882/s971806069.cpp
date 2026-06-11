#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define M_PI 3.14159265358979
#define deg_to_rad(deg) (((deg)/360)*2*M_PI)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

ll md = (ll)1e9 + 7;

int main()
{
	double a, b, x;
	cin >> a >> b >> x;

	double ans;

	if (x > a * a * b / 2) {
		double A = a * a;
		double L = 2 * b - 2 * x / A;
		ans = rad_to_deg(atan(L / a));
	}
	else {
		double L = 2 * x / (a * b);
		ans = rad_to_deg(atan(b / L));
	}

	cout << fixed << setprecision(10);
	cout << ans << endl;
	return 0;
}
