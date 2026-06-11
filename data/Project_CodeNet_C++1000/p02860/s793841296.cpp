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
	int64 nn;
	cin >> nn;
	string ss;
	cin >> ss;
	if(nn % 2 != 0)
	{
		puts("No");
		return 0;
	}
	for(int64 ii = 0;ii < nn / 2;ii++)
	{
		if(ss[ii] != ss[ii + (nn / 2)])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}