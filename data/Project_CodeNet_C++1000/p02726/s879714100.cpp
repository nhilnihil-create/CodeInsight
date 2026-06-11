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
	int64 nn, xx, yy, hoge;
	cin >> nn >> xx >> yy;
	int64 memo[nn][nn];
	xx--;yy--;
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj < nn;jj++)
		{
			memo[ii][jj] = -1;
		}
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		queue<int64> qq;
		qq.push(ii);
		memo[ii][ii] = 0;
		while(!qq.empty())
		{
			hoge = qq.front();
			qq.pop();
			vector<int64> nhoge;
			if(hoge > 0)
			{
				nhoge.push_back(hoge - 1);
			}
			if(hoge < nn - 1)
			{
				nhoge.push_back(hoge + 1);
			}
			if(hoge == xx)
			{
				nhoge.push_back(yy);
			}
			if(hoge == yy)
			{
				nhoge.push_back(xx);
			}
			for(vector<int64>::iterator ite = nhoge.begin();ite != nhoge.end();ite++)
			{
				if(memo[ii][*ite] == -1)
				{
					memo[ii][*ite] = memo[ii][hoge] + 1;
					qq.push(*ite);
				}
			}
		}
	}
	int64 ans[nn] = {0};
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj < nn;jj++)
		{
			ans[memo[ii][jj]]++;
		}
	}
	for(int64 ii = 1;ii < nn;ii++)
	{
		cout << ans[ii] / 2 << endl;
	}
	return 0;
}