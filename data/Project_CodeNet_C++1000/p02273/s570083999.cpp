#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
//const double M_PI = acos(double(-1));

struct Point{ double x, y;};

void koch(int d, Point x1, Point x2){
	if(!d) return;
	Point s, u, t;
	double th = M_PI * 60.0 / 180.0;

	s.x = (2.0 * x1.x + x2.x) / 3.0;
	s.y = (2.0 * x1.y + x2.y) / 3.0;
	u.x = (x1.x + 2.0 * x2.x) / 3.0;
	u.y = (x1.y + 2.0 * x2.y) / 3.0;
	t.x = (u.x - s.x) * cos(th) - (u.y - s.y) * sin(th) + s.x;
	t.y = (u.x - s.x) * sin(th) + (u.y - s.y) * cos(th) + s.y;

	koch(d - 1, x1, s);
	printf("%.8f %.8f\n", s.x, s.y);
	koch(d - 1, s, t);
	printf("%.8f %.8f\n", t.x, t.y);
	koch(d - 1, t, u);
	printf("%.8f %.8f\n", u.x, u.y);
	koch(d - 1, u, x2);
}

int main(){
	int n;
	cin >> n;
	Point x1, x2;
	x1.x = 0.0; x1.y = 0.0; x2.x = 100.0; x2.y = 0.0;
	printf("%.8f %.8f\n", x1.x, x1.y);
	koch(n, x1, x2);
	printf("%.8f %.8f\n", x2.x, x2.y); 
	return 0;
}