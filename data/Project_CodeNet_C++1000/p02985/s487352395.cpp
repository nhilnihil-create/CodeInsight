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

#define mod 1000000007

using namespace std;

int64 npk(uint64 nn, uint64 kk)
{
	uint64 tmp = 1;
	for(int64 ii = 0;ii < kk;ii++)
	{
		tmp *= nn;
		tmp %= mod;
		nn--;
	}
	return tmp % mod;
}

int main()
{
	uint64 nn, kk, aa, bb, ans, tmp;
	cin >> nn >> kk;
	uint64 memo[nn] = {0};
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		cin >> aa >> bb;
		memo[aa-1]++;
		memo[bb-1]++;
	}
	ans = kk;
	for(uint64 ii = 0;ii < nn;ii++)
	{
		if(ii)
			tmp = npk(kk - 2, memo[ii] - 1);
		else
			tmp = npk(kk - 1, memo[ii]);
		ans *= tmp;
		ans %= mod;
	}
	cout << ans % mod << endl;
	return 0;
}