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

vector<int64> vv;

void make(int64 bb, int64 dd)
{
	if(dd == 11)
	{
		return;
	}
	if(bb == -1)
	{
		for(int64 ii = 1;ii < 10;ii++)
		{
			vv.push_back(ii);
			make(ii, dd);
		}
		return;
	}
	int64 aa = bb % 10;
	bb *= 10;
	if(aa != 0)
	{
		vv.push_back(bb + aa - 1);
		make(bb + aa - 1, dd + 1);
	}
	vv.push_back(bb + aa);
	make(bb + aa, dd + 1);
	if(aa != 9)
	{
		vv.push_back(bb + aa + 1);
		make(bb + aa + 1, dd + 1);
	}
	return;
}

int main()
{
	int64 kk;
	cin >> kk;
	make(-1, 1);
	sort(vv.begin(), vv.end());
	cout << vv[kk - 1] << endl;
	return 0;
}