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

const int64 mod = 998244353;

int64 mpow(int64 mm, int64 xx)
{
	if(xx == 0)
	{
		return 1;
	}
	int64 tmp = mpow(mm, xx / 2);
	tmp *= tmp;
	tmp %= mod;
	if(xx % 2 == 1)
	{
		tmp *= mm;
		tmp %= mod;
	}
	return tmp;
}

int main()
{
	int64 aa, bb, cc;
	cin >> aa >> bb >> cc;
	cc -= (aa - bb);
	cout << max((int64)0, cc) << endl;
	return 0;
}