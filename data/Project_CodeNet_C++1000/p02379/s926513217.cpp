#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main()
{
	double a, b, c, d, e;
	cin >> a >> b >> c >> d;
	e = sqrt(pow(c-a, 2) + pow(d-b, 2));
	printf("%0.6f\n", e);
	return 0;
}

