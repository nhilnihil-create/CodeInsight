
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{


	int a, b;
	cin >> a >> b;
	double A = a;
	double B = b;
	double C = A / B;
	
	printf("%d %d %lf\n", a/b, a%b, C);

	return 0;
}