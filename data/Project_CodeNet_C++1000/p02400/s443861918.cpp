#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	double r;

	cin >> r;

	double S = M_PI * r * r;
	double L = 2 * M_PI * r;

	printf("%f %f\n", S, L);

	return 0;
}