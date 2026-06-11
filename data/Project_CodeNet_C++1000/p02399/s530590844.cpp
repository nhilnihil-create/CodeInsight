#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int a, b, c, d;

	cin >> a >> b;

	c = a / b;
	
	d = a % b;

	double e;

	e = (double) a / b;

	cout << c << " " << d << " ";
		
	printf("%.5f", e);

        return 0;

}