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
	int h, w;
	while (cin >> h >> w)
	{
		if (h == 0 && w == 0)
		{
			break;
		}

		for (int i = 0; i < w; i++)
		{
			cout << '#';
		}
		cout << endl;

		for (int i = 1; i < h - 1; i++)
		{
			cout << '#';
			for (int j = 1; j < w - 1; j++)
			{
				cout << '.';
			}
			cout << '#' << endl;
		}

		for (int i = 0; i < w; i++)
		{
			cout << '#';
		}
		cout << endl << endl;
	}
	return 0;
}