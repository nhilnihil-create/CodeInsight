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
	int64 hh, nn, tmp, sum = 0;
	cin >> hh >> nn;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> tmp;
		sum += tmp;
	}
	if(hh <= sum)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
