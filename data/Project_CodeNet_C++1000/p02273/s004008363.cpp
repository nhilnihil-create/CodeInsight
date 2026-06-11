#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846
typedef struct Point
{
	double dX, dY;
} P;


void Koch(int n, P pLeft, P pRight)
{
	if (0 == n)
	{
		return;
	}
	double ti = M_PI / 3.0;
	P s, u, t;
	t.dX = (pRight.dX + 2 * pLeft.dX) / 3;
	t.dY = (pRight.dY + 2 * pLeft.dY) / 3;
	u.dX = (2 * pRight.dX + pLeft.dX) / 3;
	u.dY = (2 * pRight.dY + pLeft.dY) / 3;
	s.dX = (u.dX - t.dX)*cos(ti) - (u.dY - t.dY)*sin(ti) + t.dX;
	s.dY = (u.dX - t.dX)*sin(ti) + (u.dY - t.dY)*cos(ti) + t.dY;

	Koch(n - 1, pLeft, t);
	cout << setiosflags(ios::fixed) << setprecision(8) << t.dX << " " << t.dY << endl;
	Koch(n - 1, t, s);
	cout << setiosflags(ios::fixed) << setprecision(8) << s.dX << " " << s.dY << endl;
	Koch(n - 1, s, u);
	cout << setiosflags(ios::fixed) << setprecision(8) << u.dX << " " << u.dY << endl;
	Koch(n - 1, u, pRight);
}


int main()
{
	P p1, p2;
	int n;
	p1.dX = 0;
	p1.dY = 0;
	p2.dX = 100;
	p2.dY = 0;
	cin >> n;
	cout << setiosflags(ios::fixed) << setprecision(8) << p1.dX << " " << p1.dY << endl;
	Koch(n, p1, p2);
	cout << setiosflags(ios::fixed) << setprecision(8) << p2.dX << " " << p2.dY << endl;
	return 0;
}
