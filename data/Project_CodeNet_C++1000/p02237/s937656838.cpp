#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int lld;

const lld mod = 1e9+7;
const lld INF = 1e9;
//const lld MAXN = 1e9;

int main()
{
	int n;
	cin >> n;

	int a[100][100] = {0};

	for(int i = 0; i < n; i++)
	{
		int u,k,v[100] = {0};
		cin >> u >> k;
		for(int j = 0; j < k; j++)
		{
			cin >> v[k];
			a[u-1][v[k]-1] = 1;
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (j == n-1)
			{
				cout << a[i][j] << endl;
			}else
			{
				cout << a[i][j] << " ";
			}
		}
	}

	return 0;
}