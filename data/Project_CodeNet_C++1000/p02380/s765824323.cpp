#include <iostream>
#include <string>
//g++??????
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
using namespace std;


int main(void)
{
	double a, b, angle;
	cin >> a >> b >> angle; 
	
	double radian = angle * M_PI / 180.0;
	double h = b * sin(radian);//??????
	
	double S = 1/2.0 * a * h;//??¢???

	double cc = a * a - 2 * a * b * cos(radian)+ b * b;

	double c = sqrt(cc);
	
	double L = a + b + c;//??¨?????????
	
	printf("%.4f\n%.4f\n%.4f\n", S, L, h);
	//cout << y << endl;
	
	return 0;
}