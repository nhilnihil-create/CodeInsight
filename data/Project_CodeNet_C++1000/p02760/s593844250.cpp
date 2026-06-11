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
	int64 aa[3][3];
	for(int64 ii = 0;ii < 3;ii++)
	{
		for(int64 jj = 0;jj < 3;jj++)
		{
			cin >> aa[ii][jj];
		}
	}
	int64 nn, tmp;
	cin >> nn;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> tmp;
		for(int64 jj = 0;jj < 3;jj++)
		{
			for(int64 kk = 0;kk < 3;kk++)
			{
				if(aa[jj][kk] == tmp)
				{
					aa[jj][kk] = -1;
				}
			}
		}
	}
	for(int64 ii = 0;ii < 3;ii++)
	{
		tmp = 1;
		for(int64 jj = 0;jj < 3;jj++)
		{
			if(aa[ii][jj] != -1)
			{
				tmp = 0;
			}
		}
		if(tmp)
		{
			puts("Yes");
			return 0;
		}
	}
	for(int64 ii = 0;ii < 3;ii++)
	{
		tmp = 1;
		for(int64 jj = 0;jj < 3;jj++)
		{
			if(aa[jj][ii] != -1)
			{
				tmp = 0;
			}
		}
		if(tmp)
		{
			puts("Yes");
			return 0;
		}
	}
	tmp = 1;
	for(int64 ii = 0;ii < 3;ii++)
	{
		if(aa[ii][ii] != -1)
		{
			tmp = 0;
		}
	}
	if(tmp)
	{
		puts("Yes");
		return 0;
	}
	tmp = 1;
	for(int64 ii = 0;ii < 3;ii++)
	{
		if(aa[ii][2-ii] != -1)
		{
			tmp = 0;
		}
	}
	if(tmp)
	{
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
}
