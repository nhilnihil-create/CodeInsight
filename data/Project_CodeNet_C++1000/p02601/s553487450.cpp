#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		if (a <= b && b >= c)
			c *= 2;
		else if (a >= b)
			b *= 2;
		else if (a >= c)
			c *= 2;
		else if (a <= b && b >= c)
			c *= 2;
		if (a < b && b < c)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}