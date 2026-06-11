#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

long long int psum[200001];
long long int p[200001];
int n, k;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	psum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		psum[i] = psum[i - 1] + p[i];
	}

	int idx = 0;
	long long int Max = 0;

	for (int i = 1; i <= n; i++)
	{
		int r = i + k - 1;
		if (r > n)
		{
			break;
		}
		if (psum[r] - psum[i - 1] > Max)
		{
			Max = psum[r] - psum[i - 1];
			idx = i;
		}
	}

	double res = 0;

	for (int i = idx; i < idx + k; i++)
	{
		double e = (p[i] * (p[i] + 1)) / 2;
		e /= p[i];
		res += e;
	}

	cout << fixed;
	cout.precision(16);
	
	cout << res << '\n';

	return 0;
}
