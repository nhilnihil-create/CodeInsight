#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <list>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iomanip>
#define INF 2147483647

using namespace std;



int main()
{
	double a, b, C;
	double S, L, h;

	cin >> a >> b >> C;

	S = (a * b * sin(C * M_PI / 180.0)) / 2;
	L = a + b + sqrt(pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(C * M_PI / 180.0));
	h = b * sin(C * M_PI / 180.0);

	cout << fixed << setprecision(8) << S << " " << L << " " << h << endl;
	return (0);
}