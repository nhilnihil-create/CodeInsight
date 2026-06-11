#include <iostream>
#include<cmath>
#include<stdio.h>
#define PI 3.14159265358979
using namespace std;


int main(){

	double a, b, c, C, L,S,H,rad;
	cin >> a >> b >> C;

	rad = C*PI / 180;

	S = sin(rad)*a*b / 2;
	
	c = sqrt((b*b) + (a*a) - 2 * a*b*cos(rad));

	L = a + b + c;

	H = b*sin(rad);

	printf("%.5lf", S);
	cout << " ";
	printf("%.5lf", L);
	cout << " ";
	printf("%.5lf", H);






	return 0;
}