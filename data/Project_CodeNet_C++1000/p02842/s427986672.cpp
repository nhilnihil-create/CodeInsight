#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	double x = 1;

	while (x <= n)
	{
		if (floor(x * 1.08) == n)
		{
			cout << x;
			return 0;
		}
		x++;
	}
	cout << ":(";
}