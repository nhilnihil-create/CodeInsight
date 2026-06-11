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
	int64 nn, ans = 1000000000;
	cin >> nn;
	vector<int64> ww(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> ww[ii];
	}
	for(int64 ii = 1;ii < nn;ii++)
	{
		ww[ii] += ww[ii - 1];
	}
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		ans = min(ans, abs(ww[nn - 1] - 2 * ww[ii]));
	}
	cout << ans << endl;
	return 0;
}