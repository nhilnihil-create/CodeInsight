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
	string ss;
	cin >> ss;
	for(int64 ii = 1;ii < 4;ii++)
	{
		if(ss[ii] == ss[ii - 1])
		{
			puts("Bad");
			return 0;
		}
	}
	puts("Good");
	return 0;
}