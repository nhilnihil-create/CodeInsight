#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n;
	cin >> n;
	long long nodes = 0;
	long long edges = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		edges += (long long)u * (n - v + 1);
	}
	for (int i = 0; i < n; i++) nodes += (long long)(i + 1) * (n - i);
	cout << nodes - edges << endl;
	return (0);
}
