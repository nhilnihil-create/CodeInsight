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

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn;
	cin >> nn;
	for(int64 ii = 1;ii < 50000;ii++)
	{
		if(nn < (int64)((long double)ii * 1.08))
		{
			puts(":(");
			return 0;
		}
		else if(nn == (int64)((long double)ii * 1.08))
		{
			cout << ii << endl;
			return 0;
		}
	}
	return 0;
}
