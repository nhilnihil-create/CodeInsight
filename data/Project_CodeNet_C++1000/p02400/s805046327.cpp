#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
	double a, r, s;
	cin >> a;
	r = a * a * 3.141592653589;
	s = 2 * a*3.141592653589;
	printf("%.6f %.6f\n", r, s);
	return 0;
}
