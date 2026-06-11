#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
	long int a, b, d, r;
	double f;
	cin >> a >> b;
	d = a / b;
	r = a % b;
	f = (double)a / (double)b;
	printf("%ld %ld %.6lf\n", d, r, f);
	return 0;
}
