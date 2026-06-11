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
	int64 nn, kk, fuko = 0;
	cin >> nn >> kk;
	string ss;
	cin >> ss;
	if(ss[0] == 'L')
	{
		fuko++;
	}
	for(int64 ii = 1;ii < nn;ii++)
	{
		if(ss[ii - 1] == 'R' && ss[ii] == 'L')
		{
			fuko += 2;
		}
	}
	if(ss[nn - 1] == 'R')
	{
		fuko++;
	}
	for(int64 ii = 0;ii < kk;ii++)
	{
		fuko -= 2;
		if(fuko <= 1)
		{
			cout << (nn - 1) << endl;
			return 0;
		}
	}
	cout << (nn - fuko) << endl;
	return 0;
}
