#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, dd, tmp, ll, ans = 0;
	cin >> nn >> dd;
	int64 xx[nn][dd];
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj < dd;jj++)
		{
			cin >> xx[ii][jj];
		}
	}
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		for(int64 jj = ii + 1;jj < nn;jj++)
		{
			tmp = 0;
			for(int64 kk = 0;kk < dd;kk++)
			{
				tmp += (xx[ii][kk] - xx[jj][kk]) * (xx[ii][kk] - xx[jj][kk]);
			}
			ll = 1;
			while(ll * ll < tmp)
			{
				ll++;
			}
			if(ll * ll == tmp)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}