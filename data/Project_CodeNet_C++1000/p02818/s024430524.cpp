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
	int64 aa, bb, kk;
	cin >> aa >> bb >> kk;
	if(kk <= aa)
	{
		cout << aa - kk << ' ' << bb << endl;
	}
	else if(kk <= aa + bb)
	{
		cout << "0 " << bb + aa - kk << endl;
	}
	else
	{
		cout << "0 0" << endl;
	}
	return 0;
}