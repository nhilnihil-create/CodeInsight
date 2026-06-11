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
	if(aa < 10 && bb < 10)
	{
		cout << (aa * bb) << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}
