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
	int64 nn, aa, bb, tt = 0;
	cin >> nn;
	vector<pair<int64, int64>> vv(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa >> bb;
		vv[ii].first = bb;
		vv[ii].second = aa;
	}
	sort(vv.begin(), vv.end());
	for(int64 ii = 0;ii < nn;ii++)
	{
		tt += vv[ii].second;
		if(tt > vv[ii].first)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}