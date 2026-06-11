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
	int64 nn, kk;
	cin >> nn >> kk;
	vector<int64> hh(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> hh[ii];
	}
	sort(hh.begin(), hh.end());
	auto ans = lower_bound(hh.begin(), hh.end(), kk);
	cout << distance(ans, hh.end()) << endl;
	return 0;
}
