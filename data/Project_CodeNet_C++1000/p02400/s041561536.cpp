#include <iostream>
#include <stdio.h>

#define PI 3.14159265358979

using namespace std;
typedef long long int lint;

void answer()
{
	double r;
	cin >> r;
	printf("%lf %lf\n", PI * r * r, 2 * PI * r);
}

int main()
{
	answer();
	return 0;
}