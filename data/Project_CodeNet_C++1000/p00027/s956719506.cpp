#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int m, d;
	for (; cin >> m >> d;)
	{
		if (m == 0 && d == 0)
		{
			break;
		}

		vector<int> mon = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		int mm = 0;
		for (int i = 0; i < m; i++)
		{
			mm += mon.at(i);
		}
		int y = (3 + mm + d) % 7;

		vector<string> sy = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

		cout << sy.at(y) << endl;
	}
}

