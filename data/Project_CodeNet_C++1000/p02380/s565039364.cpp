#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>

const long long int Z = 1000000007;
const long long int INF = 1 << 30;
int flag = 0;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);

}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

int main() {
	double a, b, C;
	std::cin >> a >> b >> C;
	double pi = 2.0 * asin(1.0);            /* πの値 */
	double unit = pi / 180.0;                 /* 度 → ラジアン */
	double unit_r = 180.0 / pi;                 /* ラジアン → 度 */
	double deg_r = C * unit;
	double c = sqrt(a*a + b*b - 2 * a*b*cos(deg_r));
	double S = a*b* sin(deg_r) / 2;
	double L = a + b + c;
	double h = S / a * 2;
	std::cout << std::setprecision(10) << S << ' ' << L << ' ' << h << std::endl;
	return 0;
}
