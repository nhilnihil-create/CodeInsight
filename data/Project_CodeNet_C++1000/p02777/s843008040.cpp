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
	string ss, tt, uu;
	int64 aa, bb;
	cin >> ss >> tt;
	cin >> aa >> bb;
	cin >> uu;
	if(ss == uu)
	{
		aa--;
	}
	else if(tt == uu)
	{
		bb--;
	}
	cout << aa << ' ' << bb << endl;
	return 0;
}
