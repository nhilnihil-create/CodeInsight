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

int main()
{
	int64 nn, one = 0, ans = 0, memo = 1;
	cin >> nn;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
		if(aa[ii] == 1)
		{
			one = 1;
		}
	}
	if(one == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(memo == aa[ii])
		{
			memo++;
		}
		else
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}