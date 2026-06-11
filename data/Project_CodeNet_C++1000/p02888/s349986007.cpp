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
using namespace std;

int main()
{
	int64 nn, tmp, ans = 0;
	cin >> nn;
	vector<int64> ll(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> ll[ii];
	}
	sort(ll.begin(), ll.end());
	for(int64 ii = nn - 1;ii >= 0;ii--)
	{
		for(int64 jj = ii - 1;jj >= 0;jj--)
		{
			auto ite = lower_bound(ll.begin(), ll.end(), ll[ii] + ll[jj]);
			tmp = distance(ite, ll.end());
			ans += nn - ii - 1 - tmp;
		}
	}
	cout << ans << endl;
	return 0;
}
