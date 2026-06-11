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
	string ss, tt;
	cin >> ss >> tt;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cout << ss[ii] << tt[ii];
	}
	cout << endl;
	return 0;
}