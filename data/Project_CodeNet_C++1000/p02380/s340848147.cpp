#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#define _USE_MATH_DEFINES

#include<math.h>
#include<unordered_map>

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int main()
{
	double a, b, C;

	cin >> a >> b >> C;

	double c = sqrt(a*a + b*b - 2 * a*b*cos(C / 180.0*M_PI));

	printf("%lf\n", 0.5*a*b*sin(C / 180.0*M_PI));
	printf("%lf\n", a + b + c);
	printf("%lf\n", b*sin(C / 180.0*M_PI));
}