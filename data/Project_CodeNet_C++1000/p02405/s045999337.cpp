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

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if ((i + j) % 2 == 0)
				{
					cout << '#';
				}
				else
				{
					cout << '.';
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}