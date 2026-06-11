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
	int64 nn, kk, ii = 0;
	cin >> nn >> kk;
	while(nn > 0)
	{
		ii++;
		nn /= kk;
	}
	cout << ii << endl;
	return 0;
}
