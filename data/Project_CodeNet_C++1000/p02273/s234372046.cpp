#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = atan(1) * 4;

struct Point{
	double x;
	double y;
};

void Print_Point(Point p)
{
	//ex: double n = 123.456000 
	//setprecision: 設定小數點精度 -> 123.456
	//fixed: 固定小數點精度 -> 123.45600000
	cout << fixed << setprecision(8) << p.x << " " << p.y << endl;
}

Point RotateC60(Point start, Point end)  //向量旋轉-60度 
{
	//orig: 原向量  next: 旋轉-60度的向量 
	double angle60 = PI / 3;
	Point orig = {end.x - start.x, end.y - start.y};  
	Point next = {orig.x * cos(angle60) - orig.y * sin(angle60),
				  orig.x * sin(angle60) + orig.y * cos(angle60)};
	Point u = {start.x + next.x, start.y + next.y};
	return u;
}

void Koch_Curve(Point p1, Point p2, int n)
{
	Point s = {(2*p1.x + p2.x) / 3, (2*p1.y + p2.y) / 3};
	Point t = {(2*p2.x + p1.x) / 3, (2*p2.y + p1.y) / 3};
	Point u = RotateC60(s, t);
	
	if (n > 1)
	{
		Koch_Curve(p1,  s, n-1);
		Koch_Curve( s,  u, n-1);
		Koch_Curve( u,  t, n-1);
		Koch_Curve( t, p2, n-1);
	}
	else
	{
		Print_Point(p1);
		Print_Point(s);
		Print_Point(u);
		Print_Point(t);
	}
}



int main ()
{
	int n;
	cin >> n;

	Point p1{0, 0}, p2{100, 0};
	
	if (n)
	{
		Koch_Curve(p1, p2, n);
		Print_Point(p2);
	}
	else
	{
		Print_Point(p1);
		Print_Point(p2);	
	}
	return 0;
 } 
