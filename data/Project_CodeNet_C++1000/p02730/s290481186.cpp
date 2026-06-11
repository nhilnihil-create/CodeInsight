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
	for(int64 ii = 0;ii < ss.length() / 2;ii++)
	{
		if(ss[ii] != ss[ss.length() - ii - 1])
		{
			puts("No");
			return 0;
		}
	}
	for(int64 ii = 0;ii < (ss.length() / 2) / 2;ii++)
	{
		if(ss[ii] != ss[ss.length() / 2 - ii - 1])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
