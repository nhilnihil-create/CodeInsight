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
	int64 nn;
	cin >> nn;
	if(nn % 2 == 0)
	{
		cout << "0.500000000000000000000" << endl;
	}
	else
	{
		long double ans = (nn / 2 + 1) / (long double)nn;
		cout << fixed << setprecision(15) << ans << endl;
	}
	return 0;
}
