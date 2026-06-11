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
	int64 nn, sum = 0, tmp;
	cin >> nn;
	vector<int64> aa(nn), memo(nn + 1, 0);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
		memo[aa[ii]]++;
	}
	vector<int64> cc(nn + 1, 0);
	for(int64 ii = 0;ii <= nn;ii++)
	{
		if(memo[ii] > 1)
		{
			cc[ii] = memo[ii] * (memo[ii] - 1) / 2;
		}
		sum += cc[ii];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(memo[aa[ii]] < 2)
		{
			cout << sum << endl;
		}
		else if(memo[aa[ii]] == 2)
		{
			cout << sum - 1 << endl;
		}
		else
		{
			tmp = (memo[aa[ii]] - 1) * (memo[aa[ii]] - 2) / 2;
			cout << sum - cc[aa[ii]] + tmp << endl;
		}
	}
	return 0;
}