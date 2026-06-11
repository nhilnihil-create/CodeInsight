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
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	
	while (b <= a)
	{
		if (k > 0)
		{
			b *= 2;
			k--;
		}
		else
		{
			cout << "No";
			return 0;
		}
	}
	while (c <= b)
	{
		if (k > 0)
		{
			c *= 2;
			k--;
		}
		else
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}