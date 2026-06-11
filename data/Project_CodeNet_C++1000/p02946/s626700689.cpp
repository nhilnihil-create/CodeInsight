#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <sstream>
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
	int k, x;
	cin >> k >> x;

	for (int i = 0; i < k * 2 - 1; i++)
	{
		cout << x - k + 1 << " ";
		x++;
	}
}