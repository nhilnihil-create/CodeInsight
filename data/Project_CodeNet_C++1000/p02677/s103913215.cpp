#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	int a, b, h, m;
	cin >> a >> b >> h >> m;

	long double rad = PI * 2 *
		((long double)h / 12.0 + ((long double)m / 60.0) / 12.0 - (long double)m / 60.0);

	long double rsq = (long double)(a * a + b * b) -
		(long double)(2 * a * b) * cosl(rad);

	cout << setprecision(20) << (sqrtl(rsq)) << endl;

	return 0;
}