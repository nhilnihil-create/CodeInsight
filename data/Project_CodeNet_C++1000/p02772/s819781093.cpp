#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int test; cin >> test;
	int ara[test];
	for (int i = 0; i < test; ++i)
	{
		cin >> ara[i];
		if (ara[i] % 2 == 0)
		{
			if (ara[i] % 3 == 0 || ara[i] % 5 == 0)
			{
				continue;
			}
			else
			{
				cout << "DENIED" << endl;
				return 0;
			}

		}
	}
	cout << "APPROVED" << endl;
	return 0;
}