#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

struct P { double x, y; };
double th = M_PI * 60.0 / 180.0;

void p(P p) {
	cout << p.x << " " << p.y << endl;
}

void koch(int n, P p1, P p2) {
	if (n == 0)return;

	P s, t, u;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;
	//p(s);
	//p(t);
	//p(u);

	koch(n - 1, p1, s);
	p(s);
	koch(n - 1, s, u);
	p(u);
	koch(n - 1, u, t);
	p(t);
	koch(n - 1, t, p2);

}

int main() {
	cout << fixed << setprecision(6);

	int n; cin >> n;

	P p1, p2;
	p1.x = 0; p1.y = 0;
	p2.x = 100; p2.y = 0;

	p(p1);
	koch(n, p1, p2);
	p(p2);
	return 0;
}