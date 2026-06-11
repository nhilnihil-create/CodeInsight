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
#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{
	int64 nn;
	cin >> nn;
	cout << (nn * (nn - 1) / 2) << endl;
	return 0;
}
