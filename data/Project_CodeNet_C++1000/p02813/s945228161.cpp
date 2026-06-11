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

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, aa, bb, cnt = 1;
	cin >> nn;
	vector<int64> pp(nn), qq(nn), memo(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		memo[ii] = ii + 1;
		cin >> pp[ii];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> qq[ii];
	}
	do
	{
		bool tmp1 = true, tmp2 = true;
		for(int64 ii = 0;ii < nn;ii++)
		{
			if(pp[ii] != memo[ii])
			{
				tmp1 = false;
			}
			if(qq[ii] != memo[ii])
			{
				tmp2 = false;
			}
		}
		if(tmp1)
		{
			aa = cnt;
		}
		if(tmp2)
		{
			bb = cnt;
		}
		cnt++;
	}while(next_permutation(memo.begin(), memo.end()));
	cout << abs(aa - bb) << endl;
	return 0;
}