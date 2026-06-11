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
	int64 aa, bb, cc;
	cin >> aa >> bb >> cc;
	if(aa == bb && bb != cc)
	{
		puts("Yes");
	}
	else if(bb == cc && aa != bb)
	{
		puts("Yes");
	}
	else if(aa == cc && aa != bb)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}