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
	int64 aa, bb, cc, dd, gg, ans = 0;
	cin >> aa >> bb >> cc >> dd;
	gg = gcd(cc, dd);
	gg = cc / gg;
	gg *= dd;
	
	ans += bb / cc;
	ans += bb / dd;
	ans -= bb / gg;
	
	ans -= (aa - 1) / cc;
	ans -= (aa - 1) / dd;
	ans += (aa - 1) / gg;
	
	ans = bb - aa - ans + 1;
	
	cout << ans << endl;
	return 0;
}