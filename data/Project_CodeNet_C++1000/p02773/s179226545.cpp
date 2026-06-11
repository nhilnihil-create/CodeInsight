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
	int64 nn, maxs;
	cin >> nn;
	string tmp;
	map<string, int64> ss;
	set<string> memo;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> tmp;
		ss[tmp]++;
		memo.insert(tmp);
	}
	for(set<string>::iterator ite = memo.begin();ite != memo.end();ite++)
	{
		int64 vv = ss.at(*ite);
		maxs = max(maxs, vv);
	}
	for(set<string>::iterator ite = memo.begin();ite != memo.end();ite++)
	{
		int64 vv = ss.at(*ite);
		if(vv == maxs)
		{
			cout << *ite << endl;
		}
	}
	cout << endl;
	return 0;
}
