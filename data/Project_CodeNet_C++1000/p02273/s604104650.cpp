#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <chrono>
#include <numeric>
#include <set>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <iomanip>
#include <list>

using namespace std;

double const PI = atan(1.0) * 4;

class cPoint
{
	double mx;
	double my;
public:
	cPoint() {}

	cPoint(double x, double y)
		: mx(x), my(y)
	{
	}

	cPoint operator+(const cPoint& obj2)
	{
		return cPoint(mx + obj2.mx, my + obj2.my);
	}

	cPoint operator-(const cPoint obj2)
	{
		return cPoint(mx - obj2.mx, my - obj2.my);
	}

	cPoint operator*(const double& d)
	{
		return cPoint(mx * d, my * d);
	}

	cPoint operator/(const double& d)
	{
		if (d != 0.0)
		{
			return cPoint(mx / d, my / d);
		}
		return cPoint(0.0, 0.0);
	}

	bool operator==(const cPoint& obj2)
	{
		if (mx == obj2.mx && my == obj2.my)
			return true;
		return false;
	}

	void operator()(const double& a, const double& b)
	{
		mx = a;
		my = b;
	}

	double getLength(const cPoint& obj)
	{
		return sqrt(obj.mx * obj.mx + obj.my * obj.my);
	}

	cPoint gen(const cPoint& obj1, const cPoint& obj2, const double& angle, const double mul = 1.0)
	{
		cPoint temp = obj2;
		temp = temp - obj1;
		double length = getLength(temp);

		temp.mx = length * mul * cos(angle / 180.0 * PI);
		temp.my = length * mul * sin(angle / 180.0 * PI);

		return temp;
	}

	void display(ostream& out)
	{
		out << mx << " " << my;
	}
};

ostream& operator<<(ostream& o, cPoint& d)
{
	d.display(o);
	return o;
}

class cKochCurve
{
	int mn;
	cPoint m_p1, m_p2;
	list<cPoint> lpPoints;

public:
	
	cKochCurve(int n)
		: mn(n) 
	{
		m_p1(0.0, 0.0);
		m_p2(100.0, 0.0);
		lpPoints.push_front(m_p1);
		lpPoints.push_back(m_p2);

		calc(n, m_p1, m_p2, 0);
	}
	void calc(int, cPoint, cPoint, double);
	void output();
};

void cKochCurve::calc(int n, cPoint p1, cPoint p2, double angle) 
{
	if (n == 0) return;
	list<cPoint>::iterator ilpp;
	for (list<cPoint>::iterator it = lpPoints.begin(); it != lpPoints.end(); ++it)
	{
		if (*it == p1 && it != lpPoints.end())
		{
			list<cPoint>::iterator it2 = it;
			++it2;
			if (*it2 == p2)
			{
				ilpp = it2;
				break;
			}
		}
	}
	cPoint s, t, u;
	s = p1 + (p2 - p1) * (1.0 / 3.0);
	t = p1 + (p2 - p1) * (2.0 / 3.0);
	u = s + t.gen(s, t, angle + 60.0);

	lpPoints.insert(ilpp, s); 
	lpPoints.insert(ilpp, u); 
	lpPoints.insert(ilpp, t); 

	calc(n - 1, p1, s, angle);
	calc(n - 1, s, u, angle + 60);
	calc(n - 1, u, t, angle - 60);
	calc(n - 1, t, p2, angle);
}

void cKochCurve::output()
{
	for (list<cPoint>::iterator it = lpPoints.begin(); it != lpPoints.end(); ++it)
	{
		cout << fixed << setprecision(8) << *it << endl;
	}
}

int main()
{

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();

	cKochCurve ckc(n);
	ckc.output();

	return 0;
}