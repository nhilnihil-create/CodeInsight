#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	int d, r;
	double f = 1.0;
	
	cin >> a >> b;
	d = a / b;
	r = a % b;
	f = a / (b * f);
	
	printf("%d %d %f\n", d, r, f);
	
}