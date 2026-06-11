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
	int64 nn, kk, rr, ss, pp, ans = 0;
	cin >> nn >> kk >> rr >> ss >> pp;
	string tt, memo;
	cin >> tt;
	for(int64 ii = 0;ii < kk;ii++)
	{
		if(tt[ii] == 'r')
		{
			ans += pp;
			memo += 'p';
		}
		else if(tt[ii] == 's')
		{
			ans += rr;
			memo += 'r';
		}
		else if(tt[ii] == 'p')
		{
			ans += ss;
			memo += 's';
		}
	}
	for(int64 ii = kk;ii < nn;ii++)
	{
		if(tt[ii] == tt[ii - kk])
		{
			if(memo[ii - kk] != 'o')
			{
				memo += 'o';
				continue;
			}
		}
		if(tt[ii] == 'r')
		{
			ans += pp;
			memo += 'p';
		}
		else if(tt[ii] == 's')
		{
			ans += rr;
			memo += 'r';
		}
		else if(tt[ii] == 'p')
		{
			ans += ss;
			memo += 's';
		}
	}
	cout << ans << endl;
	return 0;
}
