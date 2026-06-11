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
	int64 nn, mm, pp, sumac = 0, sumwa = 0;
	string ss;
	cin >> nn >> mm;
	vector<bool> ac(nn, false);
	vector<int64> wa(nn, 0);
	for(int64 ii = 0;ii < mm;ii++)
	{
		cin >> pp >> ss;
		pp--;
		if(ss[0] == 'A')
		{
			if(!ac[pp])
			{
				ac[pp] = true;
				sumac++;
			}
		}
		else
		{
			if(!ac[pp])
			{
				wa[pp]++;
			}
		}
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(ac[ii])
		{
			sumwa += wa[ii];
		}
	}
	cout << sumac << ' ' << sumwa << endl;
	return 0;
}
