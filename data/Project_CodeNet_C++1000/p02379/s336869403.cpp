#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	double a[2], b[2];
	double d;
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	d = sqrt(pow(b[0]-a[0],2) + pow(b[1]-a[1],2));
	printf("%.8f\n",d);
	return 0;
}