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
	int64 nn, aa;
	cin >> nn;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa;
		if(aa % 2 == 0)
		{
			if(aa % 5 == 0 || aa % 3 == 0)
			{
				continue;
			}
			else
			{
				puts("DENIED");
				return 0;
			}
		}
	}
	puts("APPROVED");
	return 0;
}