#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
#include <cctype>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)

void koch(double x1, double y1, double x2, double y2, int n)
{
	if(n <= 0) return;

	double sx = (x2 - x1)/3.0 + x1, sy = (y2 - y1)/3.0 + y1;
	double tx = (x2 - x1)/3.0 * 2 + x1, ty = (y2 - y1)/3.0 * 2 + y1;
	double ux = (tx-sx)*cos(M_PI/3.0) - (ty-sy)*sin(M_PI/3.0) + sx;
	double uy = (tx-sx)*sin(M_PI/3.0) + (ty-sy)*cos(M_PI/3.0) + sy;

	koch(x1, y1, sx, sy, n - 1);
	printf("%0.8f %8f\n", sx, sy);
	koch(sx, sy, ux, uy, n - 1);
	printf("%0.8f %8f\n", ux, uy);
	koch(ux, uy, tx, ty, n - 1);
	printf("%0.8f %8f\n", tx, ty);
	koch(tx, ty, x2, y2, n - 1);

}

int main()
{
	int n;
	cin >> n;
	double x1 = 0, y1 = 0, x2 = 100.0, y2 = 0;
	printf("%0.8f %8f\n", x1, y1);
	koch(x1, y1, x2, y2, n);
	printf("%0.8f %8f\n", x2, y2);
	return 0;
}