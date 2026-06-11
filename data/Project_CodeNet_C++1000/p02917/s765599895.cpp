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
#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{
	int64 nn, sum = 0;
	cin >> nn;
	vector<int64> bb(nn - 1);
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		cin >> bb[ii];
	}
	sum += bb[0];
	for(int64 ii = 1;ii < nn - 1;ii++)
	{
		sum += min(bb[ii], bb[ii - 1]);
	}
	sum += bb[nn - 2];
	cout << sum << endl;
	return 0;
}
