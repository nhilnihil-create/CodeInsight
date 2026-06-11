#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>


using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int h, w;
	while (1)
	{
		cin >> w >> h;
		if (h == 0 && w == 0) break;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (j == h - 1) cout << '#' << endl;
				else cout << '#';
			}
		}
		cout << endl;
	}
	return 0;
}