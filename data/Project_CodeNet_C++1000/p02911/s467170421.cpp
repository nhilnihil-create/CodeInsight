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
	int64 nn, kk, qq, tmp;
	cin >> nn >> kk >> qq;
	int64 ans[nn + 1];
	for(int64 ii = 0;ii <= nn;ii++)
	{
		ans[ii] = 0;
	}
	for(int64 ii = 0;ii < qq;ii++)
	{
		cin >> tmp;
		ans[0]--;
		ans[tmp - 1]++;
		ans[tmp]--;
		ans[nn]++;
	}
	ans[0] += kk;
	for(int64 ii = 1;ii < nn;ii++)
	{
		ans[ii] += ans[ii - 1];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(ans[ii] > 0)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}