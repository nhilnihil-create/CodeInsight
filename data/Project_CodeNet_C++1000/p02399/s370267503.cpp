
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int a,b;
	double d = 0,r = 0,f = 0;
	cin >> a >> b;
	d = a / b;
	r = a%b;
	f = 1.0 * a / b;
	printf("%.f %.f %.5lf",d,r,f);
	return 0;
}