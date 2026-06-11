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
#define coutfix(i) cout << fixed << setprecision(i)
using namespace std;

int main()
{
	int64 nn;
	cin >> nn;
	vector<int64> vv(nn);
	long double ans;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> vv[ii];
	}
	sort(vv.begin(), vv.end());
	ans = vv[0];
	for(int64 ii = 1;ii < nn;ii++)
	{
		ans += vv[ii];
		ans /= 2.0;
	}
	cout << ans << endl;
}
