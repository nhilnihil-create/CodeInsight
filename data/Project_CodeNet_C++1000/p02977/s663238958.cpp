#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n;

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	if (popcount(n) == 1)
	{
		puts("No");
		return 0;
	}
	cout << "Yes" << endl;
	if (n % 2 == 1)
	{
		cout << 1 << ' ' << 2 << '\n';
		cout << 2 << ' ' << 3 << '\n';
		cout << 3 << ' ' << n + 1 << '\n';
		cout << n + 1 << ' ' << n + 2 << '\n';
		cout << n + 2 << ' ' << n + 3 << '\n';
		for (int i = 4;i <= n;i += 2)
		{
			cout << i << ' ' << i + 1 << '\n';
			cout << i + 1 << ' ' << n + 1 << '\n';
			cout << n + 1 << ' ' << n + i << '\n';
			cout << n + i << ' ' << n + i + 1 << '\n';
		}
	}
	else
	{
		cout << 1 << ' ' << 2 << '\n';
		cout << 2 << ' ' << 3 << '\n';
		cout << 3 << ' ' << n + 1 << '\n';
		cout << n + 1 << ' ' << n + 2 << '\n';
		cout << n + 2 << ' ' << n + 3 << '\n';
		for (int i = 4;i < n;i += 2)
		{
			cout << i << ' ' << i + 1 << '\n';
			cout << i + 1 << ' ' << n + 1 << '\n';
			cout << n + 1 << ' ' << n + i << '\n';
			cout << n + i << ' ' << n + i + 1 << '\n';
		}
		int c = (n & -n);
		cout << n + c << ' ' << n << '\n';
		cout << (n - c) + 1 << ' ' << n + n << '\n';
	}
	cout.flush();
	return 0;
}