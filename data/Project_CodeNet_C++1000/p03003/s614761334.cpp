#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007
long long int result[2000][2000] = {};

int main()
{
	int n, m;
	cin >> n >> m;
	int s[2000], t[2000];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int j = 0; j < m; j++)
	{
		cin >> t[j];
	}
	result[0][0] = 1;
	if (s[0] == t[0])
		result[0][0]++;
	for (int j = 1; j < m; j++)
	{
		result[0][j] = result[0][j - 1];
		if (s[0] == t[j])
			result[0][j]++;
		result[0][j] %= mod;
	}
	for (int i = 1; i < n; i++)
	{
		result[i][0] = result[i - 1][0];
		if (s[i] == t[0])
			result[i][0]++;
		result[i][0] %= mod;
		for (int j = 1; j < m; j++)
		{
			result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1];
			if (s[i] == t[j])
				result[i][j] += result[i - 1][j - 1];
			result[i][j] += mod;
			result[i][j] %= mod;
		}
	}
	cout << result[n - 1][m - 1] << endl;
}