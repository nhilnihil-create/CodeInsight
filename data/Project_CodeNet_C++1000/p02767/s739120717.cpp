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
	int n;
	cin >> n;
	vector<int> niz(n);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> niz[i];
		sum += niz[i];
	}

	double ans_floor = floor((double)sum / n);
	double ans_ceil = ceil((double)sum / n);

	int sum_floor = 0, sum_ceil = 0;

	for (int i = 0; i < n; i++)
	{
		int x = niz[i];
		sum_floor += (x - ans_floor)*(x - ans_floor);
		sum_ceil += (x - ans_ceil)*(x - ans_ceil);
	}

	cout << min(sum_floor, sum_ceil);
}