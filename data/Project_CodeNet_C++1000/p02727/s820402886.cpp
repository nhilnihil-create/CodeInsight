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
	int64 xx, yy, aa, bb, cc;
	cin >> xx >> yy >> aa >> bb >> cc;
	vector<int64> av(aa), bv(bb), cv(cc);
	for(int64 ii = 0;ii < aa;ii++)
	{
		cin >> av[ii];
	}
	for(int64 ii = 0;ii < bb;ii++)
	{
		cin >> bv[ii];
	}
	for(int64 ii = 0;ii < cc;ii++)
	{
		cin >> cv[ii];
	}
	sort(av.begin(), av.end());
	reverse(av.begin(), av.end());
	sort(bv.begin(), bv.end());
	reverse(bv.begin(), bv.end());
	sort(cv.begin(), cv.end());
	reverse(cv.begin(), cv.end());
	int64 ans = 0;
	for(int64 ii = 0;ii < xx;ii++)
	{
		ans += av[ii];
	}
	for(int64 ii = 0;ii < yy;ii++)
	{
		ans += bv[ii];
	}
	xx--;
	yy--;
	for(int64 ii = 0;ii < cc;ii++)
	{
		if(xx == -1 && yy == -1)
		{
			break;
		}
		else if(xx == -1)
		{
			if(bv[yy] >= cv[ii])
			{
				break;
			}
			else
			{
				ans -= bv[yy];
				ans += cv[ii];
				yy--;
				continue;
			}
		}
		else if(yy == -1)
		{
			if(av[xx] >= cv[ii])
			{
				break;
			}
			else
			{
				ans -= av[xx];
				ans += cv[ii];
				xx--;
				continue;
			}
		}
		else if(av[xx] < bv[yy])
		{
			if(av[xx] >= cv[ii])
			{
				break;
			}
			else
			{
				ans -= av[xx];
				ans += cv[ii];
				xx--;
			}
		}
		else
		{
			if(bv[yy] >= cv[ii])
			{
				break;
			}
			else
			{
				ans -= bv[yy];
				ans += cv[ii];
				yy--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
