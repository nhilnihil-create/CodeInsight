#include <iostream>
#include <stdio.h>

#define PI 3.14159265359
using namespace std;


int main(){

	double r;
	double S, L;

	cin >> r;

	S = PI*r*r;
	L = 2 * PI*r;

	printf("%.8lf", S);
	cout << " ";
	printf("%.8lf\n", L);



	return 0;
}