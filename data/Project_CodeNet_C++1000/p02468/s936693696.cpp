#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <numeric>

using namespace std;
typedef long long llong;
typedef unsigned long long ullong;

const ullong MOD = 1000000000 + 7;

ullong power(ullong m, ullong n)
{
	ullong x = 1;
	if (n > 0)
	{
		x = power(m, n / 2);
		if (n % 2 == 0)
		{
			x = (x * x) % MOD;
		}
		else
		{
			x = (((x * x) % MOD) * m) % MOD;
		}
	}

	return x;
}

int main()
{
	int m, n;
	cin >> m >> n;

	cout << power(m, n) << endl;
}
