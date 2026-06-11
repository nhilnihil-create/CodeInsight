#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
#define rep(k, n)	for (int k; k < n; k++)

int main(){

	double a, b, h, m;
	cin >> a >> b >> h >> m;
	h *= 30;
	h += m / 2;
	m *= 6;
	double ans = sqrt(a*a + b*b - 2*a*b*cos(abs(h - m) / 180 * M_PI));
	cout << setprecision(20) << ans << endl;

	return 0;
} 