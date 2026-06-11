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
	int64 nn, rr;
	cin >> nn >> rr;
	if(nn >= 10)
	{
		cout << rr << endl;
	}
	else
	{
		cout << rr + 100 * (10 - nn) << endl;
	}
	return 0;
}
