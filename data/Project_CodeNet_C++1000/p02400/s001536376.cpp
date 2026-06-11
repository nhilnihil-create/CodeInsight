#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    double r,a,b;
	cin >>r;
	a=r*r*3.141592653590;
	b=2*r*3.141592653590;
	printf("%.10lf", a);
	cout <<" ";
	printf("%.10lf\n", b);
	return 0;
}