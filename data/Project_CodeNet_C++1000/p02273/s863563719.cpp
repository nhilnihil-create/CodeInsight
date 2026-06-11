#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <iomanip>
  
using namespace std;

#define pi 3.141592653589793

void koch(double sx, double sy, double ex, double ey, int n)
{
	if(n != 0){
		double x1, x2, x3, y1, y2, y3;
		double th = pi * 60.0 /180.0;
		x1 = (2 * sx + ex) / 3;
		y1 = (2 * sy + ey) / 3;
		x3 = (sx + 2 * ex) / 3;
		y3 = (sy + 2 * ey) / 3;
		x2 = (x3 - x1) * cos(th) - (y3 - y1) * sin(th) + x1;
		y2 = (x3 - x1) * sin(th) + (y3 - y1) * cos(th) + y1;
		koch(sx, sy, x1, y1, n - 1);
		printf("%f %f\n", x1, y1);
		koch(x1, y1, x2, y2, n - 1);
		printf("%f %f\n", x2, y2);
		koch(x2, y2, x3, y3, n - 1);
		printf("%f %f\n", x3, y3);
		koch(x3, y3, ex, ey, n - 1);
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	printf("%f %f\n", 0.0, 0.0);
	koch(0.0, 0.0, 100.0, 0.0, n);
	printf("%f %f\n", 100.0, 0.0);
	return 0;
}