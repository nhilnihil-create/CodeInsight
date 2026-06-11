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
	int64 nn, mm, tmp, ans = 0;
	cin >> nn >> mm;
	multiset<int64> aa;
	multiset<int64>::iterator ite;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> tmp;
		aa.insert(tmp);
	}
	for(int64 ii = 0;ii < mm;ii++)
	{
		ite = aa.end();
		ite--;
		tmp = *ite;
		ite = aa.erase(ite);
		aa.insert((int64)(tmp / 2));
	}
	for(ite = aa.begin();ite != aa.end();ite++)
	{
		ans += *ite;
	}
	cout << ans << endl;
	return 0;
}