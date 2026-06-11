#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <functional>
using namespace std;

int main()
{
	double r;
	cin >> r;
	cout.setf(ios::fixed);
	cout.precision(5);
	cout << r * r * M_PI << " " << r * 2 * M_PI << endl;
	return 0;
}