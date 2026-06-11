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
	int64 ans = 0;
	string ss;
	cin >> ss;
	for(int64 ii = 0;ii < ss.length();ii++)
	{
		if(ss[ii] != ss[ss.length() - ii - 1])
		{
			ans++;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}