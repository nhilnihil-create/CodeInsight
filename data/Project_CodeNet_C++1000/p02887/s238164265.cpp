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
	string ss;
	int64 nn, ans = 1;
	cin >> nn >> ss;
	for(int64 ii = 1;ii < nn;ii++)
	{
		if(ss[ii] != ss[ii - 1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
