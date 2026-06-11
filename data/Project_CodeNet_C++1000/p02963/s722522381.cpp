#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long s;

int main() {

	scanf("%lld", &s);

	long long x1 = 0;
	long long y1 = 0;
	long long x2 = (long long) 1e9;
	long long y2 = 1;
	long long x3 = -1;
	long long y3 = -1;

	if (s % x2 == 0) {
		y3 = s / x2;
		x3 = 0;
	} else {
		y3 = s / x2 + 1;
		x3 = x2 * y3 - s;
	}

	long long area = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;

	printf("%lld %lld %lld %lld %lld %lld\n", x1, y1, x2, y2, x3, y3);

	return 0;

}