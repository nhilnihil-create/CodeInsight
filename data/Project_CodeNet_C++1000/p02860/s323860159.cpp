#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	string sh; cin >> sh;
	if (t % 2 != 0)
	{
		cout << "No" << endl;
	}
	else
	{
		for (int i = 0, j = t / 2; i < t / 2; ++i, j++)
		{
			if (sh[i] != sh[j])
			{
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}