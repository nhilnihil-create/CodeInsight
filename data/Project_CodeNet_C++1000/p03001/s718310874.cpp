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
	int64 ww, hh, xx, yy;
	cin >> ww >> hh >> xx >> yy;
	cout << (long double)(ww * hh) / 2.0;
	if(2 * xx == ww && 2 * yy == hh)
	{
		puts(" 1");
	}
	else
	{
		puts(" 0");
	}
	return 0;
}