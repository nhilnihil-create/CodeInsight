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
	double a, b, c, d;
	std::cin >> a >> b >> c >> d;
	std::cout << std::setprecision(16) << sqrt((c - a)*(c - a) + (d - b)*(d - b)) << std::endl;
	return 0;
}
