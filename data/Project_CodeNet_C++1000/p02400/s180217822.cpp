#include <iostream>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

using namespace std;

double r;
int main(){
	cin >> r;

	printf("%f05 %f05\n", (r*r*M_PI), (r * 2 * M_PI));

	return 0;
}