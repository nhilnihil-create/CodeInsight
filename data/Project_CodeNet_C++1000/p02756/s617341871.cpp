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
	string ss, tmp;
	int64 qq, tt, ff;
	bool muki = false;
	cin >> ss >> qq;
	for(int64 ii = 0;ii < qq;ii++)
	{
		cin >> tt;
		if(tt == 1)
		{
			muki = !muki;
		}
		else
		{
			cin >> ff >> tmp;
			if(ff == 1 ^ muki)
			{
				ss = tmp + ss;
			}
			else
			{
				ss += tmp;
			}
		}
	}
	if(muki)
	{
		reverse(ss.begin(), ss.end());
	}
	cout << ss << endl;
	return 0;
}
