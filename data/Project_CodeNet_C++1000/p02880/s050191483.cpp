#include <bits/stdc++.h>
using namespace std;

bool something;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	for (int i = 1; i < 10; ++i)
	{
		if (i * 9 >= n)
		{
			for (int j = 1; j <= i; ++j)
			{
				if (i * j == n)
				{
					something = true;
					break;
				}
			}
		}
	}
	if (something)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}