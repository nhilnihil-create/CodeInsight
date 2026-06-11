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

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, ff, bb, ans = 0;
	cin >> nn;
	map<pair<int64, int64>, int64> memo;
	for(int64 ii = 1;ii <= nn;ii++)
	{
		for(int64 jj = 1;true;jj *= 10)
		{
			if(jj > ii)
			{
				break;
			}
			ff = ii / jj;
		}
		bb = ii % 10;
		memo[make_pair(ff, bb)]++;
	}
	for(int64 ii = 1;ii <= 9;ii++)
	{
		for(int64 jj = 1;jj <= 9;jj++)
		{
			ans += memo[make_pair(ii, jj)] * memo[make_pair(jj, ii)];
		}
	}
	cout << ans << endl;
	return 0;
}
