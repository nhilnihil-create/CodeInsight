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
	int64 nn, ans = 0;
	cin >> nn;
	vector<int64> aa(nn + 1), memo(nn + 1, 0);
	for(int64 ii = 1;ii <= nn;ii++)
	{
		cin >> aa[ii];
		if(ii - aa[ii] > 0)
		{
			memo[ii - aa[ii]]++;
		}
	}
	for(int64 ii = 1;ii <= nn;ii++)
	{
		if(aa[ii] + ii <= nn)
		{
			ans += memo[aa[ii] + ii];
		}
	}
	cout << ans << endl;
	return 0;
}