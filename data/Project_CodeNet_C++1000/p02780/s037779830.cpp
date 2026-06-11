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

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, kk;
	cin >> nn >> kk;
	vector<int64> pp(nn + 1, 0);
	long double ans = 0, tmp;
	for(int64 ii = 1;ii <= nn;ii++)
	{
		cin >> pp[ii];
		pp[ii] += 1;
		pp[ii] += pp[ii - 1];
	}
	for(int64 ii = 0;ii <= (nn - kk);ii++)
	{
		tmp = pp[ii + kk] - pp[ii];
		tmp /= 2.0;
		ans = ans < tmp ? tmp : ans;
	}
	cout << fixed << setprecision(15) << ans << endl;;
	return 0;
}
