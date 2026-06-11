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
	int64 nn;
	cin >> nn;
	vector<int64> xx(nn), yy(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> xx[ii] >> yy[ii];
	}
	long double sum = 0.0;
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj < nn;jj++)
		{
			sum += sqrtl((long double)((xx[ii] - xx[jj]) * (xx[ii] - xx[jj]) + (yy[ii] - yy[jj]) * (yy[ii] - yy[jj])));
		}
	}
	sum /= (long double)nn;
	cout << fixed << setprecision(20);
	cout << sum << endl;
	return 0;
}