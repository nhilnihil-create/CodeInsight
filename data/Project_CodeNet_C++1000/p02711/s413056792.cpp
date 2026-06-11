#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh; cin >> sh;
	for (int i = 0; i < 3; ++i)
	{
		if (sh[i] == '7')
		{
			cout << "Yes" << endl;
			return 0;
		}

	}
	cout << "No" << endl;

	return 0;
}