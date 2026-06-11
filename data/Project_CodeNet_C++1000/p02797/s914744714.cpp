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
	int64 nn, kk, ss;
	cin >> nn >> kk >> ss;
	for(int64 ii = 0;ii < kk;ii++)
	{
		cout << ss << ' ';
	}
	for(int64 ii = kk;ii < nn;ii++)
	{
		cout << (ss == 1000000000 ? 1 : ss + 1) << ' ';
	}
	cout << endl;
	return 0;
}