#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double calcS(int a, int b, int d);
double calcL(int a, int b, int d);
double calcH(int b, int d);

int main(void)
{	
	int a, b, d;
	cin >> a >> b >> d;
	
	cout << fixed << calcS(a, b, d) << endl;
	cout << fixed << calcL(a, b, d) << endl;
	cout << fixed << calcH(b, d) << endl;
	
	return 0;
}

double calcS(int a, int b, int d)
{
	return a * b * sin(d / 180.0 * M_PI) / 2;
}

double calcL(int a, int b, int d)
{
	double c = sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(d / 180.0 * M_PI)));
	return a + b + c;
}

double calcH(int b, int d)
{
	return b * sin(d / 180.0 * M_PI);
}