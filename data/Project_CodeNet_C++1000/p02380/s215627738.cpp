#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <numeric>
#include <regex>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include <cctype>

//#include <map>

using namespace std;

int main()
{
	double a, b, c;
	double deg, rad;
	double S, L, h;
	double ad;

	cin >> a >> b >> deg;

	rad = deg / 180.0 * M_PI;
	ad = a - (b * cos(rad));
	h = b * sin(rad);
	c = sqrt(ad * ad + h * h);
	S = a * h / 2;
	L = a + b + c;

	cout << fixed << setprecision(8) << S << endl;
	cout << fixed << setprecision(8) << L << endl;
	cout << fixed << setprecision(8) << h << endl;

	return 0;
}