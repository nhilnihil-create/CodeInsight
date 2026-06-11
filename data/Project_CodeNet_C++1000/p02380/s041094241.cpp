#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

void solve()
{
	int a, b, C;
	cin >> a >> b >> C;
	double S = 0.5 * a * b * sin(C * M_PI / 180);
	double h = 2 * S / a;
	double c = sqrt(a * a + b * b - 2 * a * b * cos(C * M_PI / 180));
	printf("%.6f\n%.6f\n%.6f\n", S, a + b + c, h);
}

int main()
{
	solve();
	return(0);
}