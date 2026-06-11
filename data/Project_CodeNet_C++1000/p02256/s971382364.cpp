#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <functional>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int x, y; //y<xとする。
	if (a > b)
	{
		x = a;
		y = b;
	}
	else
	{
		x = b;
		y = a;
	}

	while (true)
	{
		if (x % y == 0)
		{
			cout << y << endl;
			break;
		}
		else
		{
			int q = x % y;
			x = y;
			y = q;
		}
	}
	return 0;
}