#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
	double x,y;
};

vector<Point> ans;

// l:left, r:right, d:depth
void koch(Point l, Point r, int d) {
	if (d == 0) {
		ans.push_back(l);
		return;
	}
	Point s, t, u;
	double th = M_PI / 3;
	s.x = (2*l.x + 1*r.x) / 3;
	s.y = (2*l.y + 1*r.y) / 3;
	t.x = (1*l.x + 2*r.x) / 3;
	t.y = (1*l.y + 2*r.y) / 3;
	u.x = (t.x-s.x)*cos(th) - (t.y-s.y)*sin(th) + s.x;
	u.y = (t.x-s.x)*sin(th) + (t.y-s.y)*cos(th) + s.y;
	koch(l, s, d-1);
	koch(s, u, d-1);
	koch(u, t, d-1);
	koch(t, r, d-1);
}

int main(){
	int n;
	cin >> n;
	Point left, right;
 	left.x = left.y = 0;
	right.x = 100;
	right.y = 0;
	koch(left, right, n);
	// 最後の点が入らないので
	ans.push_back(right);
	for (int i=0;i<ans.size();++i) {
		printf("%.8f %.8f", ans[i].x, ans[i].y); cout << endl;
	}
	return 0;
}


