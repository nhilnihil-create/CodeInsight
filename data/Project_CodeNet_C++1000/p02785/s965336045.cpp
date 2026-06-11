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
	int64 nn, kk, sum = 0;
	cin >> nn >> kk;
	vector<int64> hh(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> hh[ii];
	}
	sort(hh.begin(), hh.end());
	reverse(hh.begin(), hh.end());
	for(int64 ii = kk;ii < nn;ii++)
	{
		sum += hh[ii];
	}
	cout << sum << endl;
	return 0;
}
