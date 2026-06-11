#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

void solve()
{
	double r;
	cin >> r;
	printf("%.6f %.6f\n", r * r * M_PI, 2 * M_PI * r);
}

int main()
{
	solve();
	return(0);
}