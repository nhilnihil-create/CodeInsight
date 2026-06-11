#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	double a, b, c; cin >> a >> b >> c;
	double d = sqrt(a*a + b*b - 2 * a*b*cos(c / 180 * M_PI));
	double z = (a + b + d) / 2;
	double ar = sqrt(z*(z - a)*(z - b)*(z - d));
	printf("%.7lf\n%.7lf\n%.7lf\n", ar, a + b + d, ar * 2 / a);
}