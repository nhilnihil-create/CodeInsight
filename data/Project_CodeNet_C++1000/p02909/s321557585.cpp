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
	string ss;
	cin >> ss;
	if(ss[0] == 'S')
	{
		cout << "Cloudy" << endl;
	}
	else if(ss[0] == 'C')
	{
		cout << "Rainy" << endl;
	}
	else
	{
		cout << "Sunny" << endl;
	}
	return 0;
}