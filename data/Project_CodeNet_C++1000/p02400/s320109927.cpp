#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
	const double pai = 3.141592653589;
	double r;
	cin >> r;
	printf("%.5lf %.5lf\n",pai * r * r,2 * pai * r);
	return 0;
}