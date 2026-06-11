#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
	double a, b;
	int  d, r;
	double f;
	cin >> a >> b;
	d = (int) (a / b);
	r = (int) a % (int) b;
	f = a / b;
	printf("%d %d %.5f", d, r, f);
	return 0;
}


