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
using namespace std;

int main()
{
	int64 nn, ans = 1000000000000000;
	cin >> nn;
	for(int64 ii = 1;ii <= sqrt(nn);ii++)
	{
		if(nn % ii == 0)
		{
			ans = min(ans, ii + (nn / ii) - 2);
		}
	}
	cout << ans << endl;
	return 0;
}
