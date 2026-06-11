#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	double x1, x2, y1, y2, x, y,l;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 >= 0 && x2 >= 0)
	{
		if (x1 > x2)
		{
			x = x1 - x2;
		}
		else
		{
			x = x2 - x1;
		}
	}
	else if (0 < x1 && x2 < 0)
	{
		x = x1 - x2;
	}
	else if (x1 < 0 && 0 < x2)
	{
		x = x2 - x1;
	}
	else if (x1 < 0 && x2 < 0)
	{
		if (x1 < x2)
		{
			x = x2 - x1;
		}
		else if (x2 < x1)
		{
			x = x1 - x2;
		}
	}

	if (y1 >= 0 && y2 >= 0)
	{
		if (y1 > y2)
		{
			y = y1 - y2;
		}
		else
		{
			y = y2 - y1;
		}
	}
	else if (0 < y1 && y2 < 0)
	{
		y = y1 - y2;
	}
	else if (y1 < 0 && 0 < y2)
	{
		y = y2 - y1;
	}
	else if (y1 < 0 && y2 < 0)
	{
		if (y1 < y2)
		{
			y = y2 - y1;
		}
		else if (y2 < y1)
		{
			y = y1 - y2;
		}
	}

	l = sqrt((x*x) + (y*y));

	cout << fixed << std::setprecision(6) << l << endl;

	return 0;
}