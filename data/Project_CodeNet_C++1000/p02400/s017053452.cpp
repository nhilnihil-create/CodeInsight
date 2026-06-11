#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	double r, p, m;

	cin >> r;

	p = r * r * 3.141592653589;

	m = r * 2 * 3.141592653589;

	printf("%f" , p);
	printf(" ");
	printf("%f" , m);

}