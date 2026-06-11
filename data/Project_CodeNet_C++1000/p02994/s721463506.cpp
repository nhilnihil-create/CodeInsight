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
	int64 nn, ll;
	cin >> nn >> ll;
	int64 sum = 0;
	for(int64 ii = 0;ii < nn;ii++)
	{
		int64 tmp = ll + ii;
		sum += tmp;
	}
	if(ll + nn - 1 < 0)
	{
		sum -= (ll + nn - 1);
	}
	else if(ll > 0)
	{
		sum -= ll;
	}
	cout << sum << endl;
	return 0;
}