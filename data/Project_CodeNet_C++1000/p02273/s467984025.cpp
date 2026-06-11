#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;
struct vertex { double x, y; };

void kock(int d, vertex p1, vertex p2)
{
	if (d == 0)
		return;

	vertex s, t, u;
	s.x = (2 * p1.x + 1 * p2.x) / 3;
	s.y = (2 * p1.y + 1 * p2.y) / 3;
	t.x = (1 * p1.x + 2 * p2.x) / 3;
	t.y = (1 * p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x) * cos(M_PI / 3) - (t.y - s.y) * sin(M_PI / 3) + s.x;
	u.y = (t.x - s.x) * sin(M_PI / 3) + (t.y - s.y) * cos(M_PI / 3) + s.y;

	kock(d - 1, p1, s);
	cout << s.x << " " << s.y << endl;
	kock(d - 1, s, u);
	cout << u.x << " " << u.y << endl;
	kock(d - 1, u, t);
	cout << t.x << " " << t.y << endl;
	kock(d - 1, t, p2);
}

int main()
{
	int n;
	cin >> n;

	vertex p1, p2;
	p1.x = 0.0, p1.y = 0.0;
	p2.x = 100.0, p2.y = 0.0;

	cout << p1.x << " " << p1.y << endl;
	kock(n, p1, p2);
	cout << p2.x << " " << p2.y << endl;

	return 0;
}