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
	int64 nn, sum = 0, tmp = 0;
	cin >> nn;
	int64 aa[nn], ans[nn] = {0};
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
		sum += aa[ii];
	}
	for(int64 ii = 1;ii < nn;ii += 2)
	{
		tmp += aa[ii];
	}
	ans[0] = sum - 2 * tmp;
	for(int64 ii = 1;ii < nn;ii++)
	{
		ans [ii] = 2 * aa[ii - 1] - ans[ii - 1];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		cout << ans[ii] << ' ';
	}
	cout << endl;
	return 0;
}