#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <iomanip>
#include <iterator>
#include <utility>

typedef long long ll;
typedef unsigned long long ull;

int main() {
	ull a, b, c, d, n, c_r, d_r;
	std::cin >> a >> b >> c >> d;
	c_r = c;
	d_r = d;
	if (c < d) {
		std::swap(c, d);
		std::swap(c_r, d_r);
	}
	for (int i = 0; i < c; ++i) {
		n = c % d;
		c = d;
		if (n == 0) {
			break;
		}
		d = n;
	}
	a -= 1;
	std::cout << (b - (b / c_r) - (b / d_r) + (b / (c_r * d_r / d))) - (a - (a / c_r) - (a / d_r) + (a / (c_r * d_r / d))) << std::endl;
}