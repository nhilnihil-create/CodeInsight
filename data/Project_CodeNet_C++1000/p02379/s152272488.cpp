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
	double x1, y1, x2, y2;
	double x, y;
	double theta;
	double d;

	cin >> x1 >> y1 >> x2 >> y2;

	x = x2 - x1;
	y = y2 - y1;
	d = sqrt(x * x + y * y);

	cout << fixed << setprecision(6) << d << endl;
}