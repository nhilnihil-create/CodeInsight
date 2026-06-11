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
	int64 nn, mm;
	cin >> nn >> mm;
	vector<int64> aa(nn + 1, -1);
	int64 ss, cc;
	for(int64 ii = 0;ii < mm;ii++)
	{
		cin >> ss >> cc;
		if(aa[ss] == -1 || aa[ss] == cc)
		{
			aa[ss] = cc;
		}
		else
		{
			puts("-1");
			return 0;
		}
	}
	if(aa[1] == 0 && nn != 1)
	{
		puts("-1");
		return 0;
	}
	else if(aa[1] == -1 && nn == 1)
	{
		aa[1] = 0;
	}
	else if(aa[1] == -1)
	{
		aa[1] = 1;
	}
	for(int64 ii = 2;ii <= nn;ii++)
	{
		if(aa[ii] == -1)
		{
			aa[ii] = 0;
		}
	}
	for(int64 ii = 1;ii <= nn;ii++)
	{
		cout << aa[ii];
	}
	cout << endl;
	return 0;
}
