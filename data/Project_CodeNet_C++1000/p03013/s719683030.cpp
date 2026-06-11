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
#define coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

int64 memo[1000000];

int64 sol(int64 xx, int64 mod)
{
	if(xx < 0)
	{
		return 0;
	}
	if(memo[xx] == -1)
	{
		int64 tmp = sol(xx - 1, mod);
		tmp += sol(xx - 2, mod);
		memo[xx] = tmp;
		memo[xx] %= mod;
		return memo[xx];
	}
	else
	{
		return memo[xx];
	}
	return 0;
}

int main()
{
	int64 nn, mm, tmp, ans, mod = 1000000007;
	cin >> nn >> mm;
	for(int64 ii = 0;ii <= nn;ii++)
	{
		memo[ii] = -1;
	}
	for(int64 ii = 0;ii < mm;ii++)
	{
		cin >> tmp;
		memo[tmp] = 0;
	}
	memo[0] = 1;
	ans = sol(nn, mod);
	ans %= mod;
	cout << ans << endl;
	return 0;
}