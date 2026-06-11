#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	if (__builtin_popcount(n) == 1)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << 1 << ' ' << 2 << endl;
	cout << 2 << ' ' << 3 << endl;
	cout << 3 << ' ' << n + 1 << endl;
	cout << n + 1 << ' ' << n + 2 << endl;
	cout << n + 2 << ' ' << n + 3 << endl;
	for (int i = 4; i < n; i += 2)
	{
		cout << n + 1 << ' ' << i << endl;
		cout << n + 1 << ' ' << i + n + 1 << endl;
		cout << i << ' ' << i + 1 << endl;
		cout << i + n + 1 << ' ' << i + n << endl;
	}
	if (n % 2 == 0)
	{
		for (int i = 2; i <= n; i++)
		{
			int u = (i == 2 || i % 2 == 1) ? i + n : i; 
			if ((n ^ i ^ 1) < n)
			{
				int v = ((n ^ i ^ 1) == 2 || (n ^ i ^ 1) % 2 == 1) ? (n ^ i ^ 1) + n : (n ^ i ^ 1);
				cout << u << ' ' << n << endl;
				cout << 2 * n << ' ' << v << endl;
				break;
			}
		}
	}
	return 0;
}
