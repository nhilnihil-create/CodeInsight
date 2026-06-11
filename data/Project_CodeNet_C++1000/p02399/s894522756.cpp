#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int a, b;
	int d, r;
	double f;

	cin >> a >> b;

	d = a / b;
	r = a%b;
	f = 1.00000 * a / b;

	printf("%d %d %.5lf\n", d, r, f);
}