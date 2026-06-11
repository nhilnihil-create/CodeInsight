#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#define _USE_MATH_DEFINES

#include<math.h>
#include<unordered_map>

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

void shell_sort(int a[], int n)
{
	const int G[] = { 1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913, 1050113 };
	int cnt = 0;
	int m = 0;
	while (true)
	{
		m++;
		if (G[m] > n)
		{
			break;
		}
	}

	cout << m << endl;

	for (int i = m - 1; i != -1; i--)
	{
		for (int j = G[i]; j < n; j++)
		{
			int v = a[j];
			int k = j - G[i];
			while (k >= 0 && a[k] > v)
			{
				a[k + G[i]] = a[k];
				k -= G[i];
				cnt++;
			}
			a[k + G[i]] = v;
		}
		cout << G[i];
		if (i > 0)
		{
			cout << " ";
		}
	}
	cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

int main()
{
	int n;
	static int a[1000000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	shell_sort(a, n);
	return 0;
}