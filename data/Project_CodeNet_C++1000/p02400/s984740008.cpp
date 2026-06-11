#include <iostream>
#include <cstdio>

using namespace std;

const double PI = 3.141592653589;

int main()
{
	double r;
	cin >> r;
	printf("%f %f\n", PI*r*r, 2.0*PI*r);

	return 0;
}