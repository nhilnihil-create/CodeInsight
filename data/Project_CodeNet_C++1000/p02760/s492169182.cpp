/*https://atcoder.jp/contests/abc157/tasks/abc157_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n = 3, a[100][100], b[10], m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
				if (a[i][j] == b[k] && b[k] != 0) a[i][j] = 0, b[k] = 0;

		}
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
			if (a[i][j] == 0) count++;
		if (count == n)
		{
			cout << "Yes";
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
			if (a[j][i] == 0) count++;
		// cout << count << endl;

		if (count == n)
		{
			cout << "Yes";
			return 0;
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (i == j && a[i][j] == 0) count++;
		if (count == n)
		{
			cout << "Yes";
			return 0;
		}
	}
	count = 0;
	for (int i = 0; i < n; i++)
	{
		// int count = 0;
		for (int j = 0; j < n; j++)
			if (i + j == n - 1 && a[i][j] == 0) count++;
		if (count == n)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No" << endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		cout << a[i][j] << " ";
	// 	cout << endl;
	// }
	// for (int i = 0; i < m; i++)
	// 	cout << b[i] << " ";

}