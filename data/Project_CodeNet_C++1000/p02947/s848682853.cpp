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
	int64 nn, ans = 0;
	string str;
	cin >> nn;
	vector<int64> ss(nn, 0);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> str;
		sort(str.begin(), str.end());
		for(int64 jj = 0;jj < 10;jj++)
		{
			ss[ii] += (int64)(pow(26, jj)) * (str[jj] - 'a');
		}
	}
	sort(ss.begin(), ss.end());
	for(int64 ii = 0;ii < nn - 1;ii++)
	{
		for(int64 jj = ii + 1;jj < nn;jj++)
		{
			if(ss[ii] == ss[jj])
			{
				ans++;
			}
			else
			{
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}