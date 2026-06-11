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
	int64 aa, bb;
	cin >> aa >> bb;
	for(int64 ii = 1;ii < 1100;ii++)
	{
		if(ii * 2 / 25 == aa && ii / 10 == bb)
		{
			cout << ii << endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}
