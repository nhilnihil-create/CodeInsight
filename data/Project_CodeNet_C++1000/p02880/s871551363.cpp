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
	for(int64 ii = 1;ii < 10;ii++)
	{
		for(int64 jj = 1;jj < 10;jj++)
		{
			if(nn == ii * jj)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
