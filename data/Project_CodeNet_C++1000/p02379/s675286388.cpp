#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 100000;
const double pi = 3.141592653589;

int main()
{
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	printf("%.9f\n",sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
	return 0;
}