#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <ostream>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iomanip>

#define N 2005
#define INF (1 << 30)
using namespace std;
struct coordinate {
	double x, y;
};
const double PI = 2.0 * acos(0.0);
const double cos60 = cos(PI / 3.0);
const double sin60 = sin(PI / 3.0);
void koch(int n, coordinate p1, coordinate p2)
{
	if (n == 0)
	{
		printf("%.8lf %.8lf\n", p1.x, p1.y);
		return;
	}
	coordinate s, t, u;
	s.x = (2 * p1.x + p2.x) / 3.0;
	s.y = (2 * p1.y + p2.y) / 3.0;
	t.x = (p1.x + 2 * p2.x) / 3.0;
	t.y = (p1.y + 2 * p2.y) / 3.0;
	u.x = (t.x - s.x) * cos60 - (t.y - s.y) * sin60 + s.x;
	u.y = (t.x - s.x) * sin60 + (t.y - s.y) * cos60 + s.y;
	koch(n - 1, p1, s);
	koch(n - 1, s, u);
	koch(n - 1, u, t);
	koch(n - 1, t, p2);
}

int main()
{
	int n;
	cin >> n;
	coordinate p1, p2;
	p1.x = 0.0;
	p1.y = 0.0;
	p2.x = 100.0;
	p2.y = 0.0;
	koch(n, p1, p2);
	printf("%.8lf %.8lf\n", p2.x, p2.y);
	return 0;
}