#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= 3; i++)
	{
		if (a != i && b != i)
		{
			cout << i;
			return 0;
		}
	}
}