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
	int64 nn, minm, maxm;
	cin >> nn;
	vector<int64> aa(nn), bb(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii] >> bb[ii];
	}
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	if(nn % 2 == 1)
	{
		minm = aa[nn / 2];
		maxm = bb[nn / 2];
	}
	else
	{
		minm = aa[nn / 2 - 1] + aa[nn / 2];
		maxm = bb[nn / 2 - 1] + bb[nn / 2];
	}
	cout << (maxm - minm + 1) << endl;
	return 0;
}
