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
#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{
	int64 nn, ans = 0;
	cin >> nn;
	vector<int64> aa(nn + 1), bb(nn + 1), cc(nn);
	for(int64 ii = 1;ii <= nn;ii++)
	{
		cin >> aa[ii];
	}
	for(int64 ii = 1;ii <= nn;ii++)
	{
		cin >> bb[ii];
	}
	for(int64 ii = 1;ii <= nn - 1;ii++)
	{
		cin >> cc[ii];
	}
	ans += bb[aa[1]];
	for(int64 ii = 2;ii <= nn;ii++)
	{
		ans += bb[aa[ii]];
		if(aa[ii] - aa[ii - 1] == 1)
		{
			ans += cc[aa[ii - 1]];
		}
	}
	cout << ans << endl;
	return 0;
}
