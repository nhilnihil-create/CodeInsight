/*
时间:2020-7-31
书籍：算法和数据结构
内容：科赫曲线
页数：P116
*/
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
const double PI = 3.1415926535;
class Point
{
public:
	double x;
	double y;
	Point(double x=0, double y=0)
	{
		this->x = x; 
		this->y = y;
	}
};
void koch(int n, Point a, Point b)
{
	if (n == 0)
		return;
	Point s, t, u;
	double th =PI* 60.0 / 180.0;
	s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
	s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
	t.x = (2.0 * b.x + 1.0 * a.x) / 3.0;
	t.y = (2.0 * b.y + 1.0 * a.y) / 3.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;           //通过旋转矩阵获得
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

	koch(n - 1, a, s);
	cout << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	koch(n - 1, t, b);
	 
}
int main()
{
	cout << setprecision(10);
	Point a(0, 0), b(100, 0);
	int n;
	cin >> n;
	cout << a.x << " " << a.y << endl;
	koch(n, a, b);
	cout << b.x << " " << b.y << endl;
	return 0;
}
