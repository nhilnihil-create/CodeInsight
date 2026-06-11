
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	double r=0.0;
	cin >> r;

	printf("%f %f\n", M_PI*r*r, 2*r*M_PI);
	
	
	//cout << M_PI*r*r << " " << 2 * r*M_PI << endl;
	//system("pause");
	return 0;
}