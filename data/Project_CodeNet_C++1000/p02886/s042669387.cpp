#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, sum = 0;
	cin >> nn;
	vector<int64> dd(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> dd[ii];
	}
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		for(int64 jj = ii + 1;jj < nn;jj++)
		{
			sum += dd[ii] * dd[jj];
		}
	}
	cout << sum << endl;
	return 0;
}
