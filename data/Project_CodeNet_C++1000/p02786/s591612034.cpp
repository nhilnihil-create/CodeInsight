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
	int64 hh, num = 1,sum = 0;
	cin >> hh;
	while(hh >= 1)
	{
		sum += num;
		hh /= 2;
		num *= 2;
	}
	cout << sum;
	return 0;
}
