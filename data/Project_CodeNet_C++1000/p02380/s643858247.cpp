#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <iomanip>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
#include <cmath>

using namespace std;

int main(){

	double a, b, c, d, h, C, S, L;

	cin >> a >> b >> C;

	h = b * sin(C * M_PI / 180);
	d = b * cos(C * M_PI / 180);
	c = sqrt(pow(a - d, 2) + pow(h, 2));
	S = a * h / 2;
	L = a + b + c;

	printf("%.6f\n%.6f\n%.6f\n", S, L, h);


	return 0;
}