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
using namespace std;

int main()
{
	int64 aa, bb, xx;
	cin >> aa >> bb >> xx;
	long double mm, cc = 90.0, dd = 0.0, tmp;
	while(cc - dd >= 0.0000001)
	{
		mm = (cc + dd) / 2.0;
		if(bb * tanl(PI * (90.0 - mm) / 180.0) <= aa)
		{
			tmp = bb * bb * tanl(PI * (90.0 - mm) / 180.0) * aa / 2.0;
		}
		else
		{
			tmp = aa * aa * bb - aa * aa * aa * tanl(PI * mm / 180.0) / 2.0;
		}
		if(tmp < xx)
		{
			cc = mm;
		}
		else
		{
			dd = mm;
		}
	}
	cout << fixed << setprecision(15);
	cout << mm << endl;
	return 0;
}
