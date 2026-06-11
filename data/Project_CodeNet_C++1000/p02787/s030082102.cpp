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
	int64 hh, nn;
	cin >> hh >> nn;
	vector<int64> aa(nn), bb(nn), memo(hh + 1, 1e18);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii] >> bb[ii];
	}
	memo[0] = 0;
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj <= hh;jj++)
		{
			if(memo[min(jj + aa[ii], hh)] > memo[jj] + bb[ii])
			{
				memo[min(jj + aa[ii], hh)] = memo[jj] + bb[ii];
			}
		}
	}
	cout << memo[hh] << endl;
	return 0;
}
