#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

#define _USE_MATH_DEFINES
#include<math.h>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
int N;

struct Point{ double x, y; };

void render(Point p){
	cout << p.x << " " << p.y << endl;
}

void rec(Point p1, Point p2, int n){
	if (n == N) return;

	Point s, t, u;
	s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
	s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
	t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
	t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;

	double th = M_PI * 60.0 / 180.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

	if (n != N) rec(p1, s, n + 1);
	render(s);
	if (n != N) rec(s, u, n + 1);
	render(u);
	if (n != N) rec(u, t, n+1);
	render(t);
	if (n != N) rec(t, p2, n + 1);

}

int main() {

	cin >> N;
	double x1, y1, x2, y2;
	
	Point p1, p2;
	p1.x = 0.0; p1.y= 0.0;
	p2.x = 100.0; p2.y = 0.0;

	render(p1);
	rec(p1, p2, 0);
	render(p2);
}