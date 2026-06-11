#include <bits/stdc++.h>
using namespace std;
struct dot {
	double x;
	double y;
};

int koch(int n, dot p1, dot p2) {
	double pi = 3.141592653;
	dot u, s, t;
	if (n==0) {
		return 0;
	}
	
	s.x = (2 * p1.x + 1 * p2.x) / 3;
	s.y = (2 * p1.y + 1 * p2.y) / 3;
	t.x = (1 * p1.x + 2 * p2.x) / 3;
	t.y = (1 * p1.y + 2 * p2.y) / 3;
	u.x = ((t.x - s.x) * cos(pi / 3) - (t.y - s.y) * sin(pi / 3) + s.x);
	u.y = ((t.x - s.x) * sin(pi / 3) + (t.y - s.y) * cos(pi / 3) + s.y);


	koch(n-1, p1, s);
	cout << s.x << " "<< s.y<<endl;
	koch(n-1, s, u);
	cout << u.x << " " << u.y<<endl;
	koch(n-1, u, t);
	cout << t.x << " " << t.y<<endl;
	koch(n-1, t, p2);	
	return 0;

}


int main() {
	int n;
	dot begin = { 0,0 };
	dot end = { 100,0 };

	cin >> n;
	cout << begin.x <<" "<< begin.y << endl;
	koch(n, begin,end);
	cout << end.x << " " << end.y << endl;
	
	return 0;
}

