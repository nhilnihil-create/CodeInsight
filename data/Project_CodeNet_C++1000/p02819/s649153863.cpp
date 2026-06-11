/*https://atcoder.jp/contests/abc149/tasks/abc149_c*/
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
	long long x, n = 1e6 + 1;
	cin >> x;
	if (x == 2)
	{
		cout << "2";
		return 0;
	}
	// int flag = 0;
	for (int i = x; i < n; i++)
	{
		int flag = 0;
		for (int j = 2; j < i; j++)
		{
			// cout << i << " " << j << "->" << i % j << endl;
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << i;
			return 0;
		}
	}
}