#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	long long a, b, k;
	cin >> a >> b >> k;
	a -= k;
	if (a < 0) {
		b += a;
		a = 0;
	}
	if (b < 0) { b = 0; }
	printf("%lld %lld", a, b);
	return 0;
}