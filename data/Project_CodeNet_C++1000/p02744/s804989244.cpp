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
	int64 nn;
	cin >> nn;
	set<string> ans;
	queue<pair<string, char>> qq;
	qq.push(make_pair("a", 'b'));
	while(!qq.empty())
	{
		string tmps = qq.front().first;
		char tmpc = qq.front().second;
		qq.pop();
		if(tmps.length() == nn)
		{
			ans.insert(tmps);
			continue;
		}
		for(char cc = 'a';cc <= tmpc;cc++)
		{
			if(cc == tmpc)
			{
				qq.push(make_pair(tmps + cc, tmpc + 1));
			}
			else
			{
				qq.push(make_pair(tmps + cc, tmpc));
			}
		}
	}
	for(set<string>::iterator ite = ans.begin();ite != ans.end();ite++)
	{
		cout << *ite << endl;
	}
	return 0;
}