#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh, sh1; cin >> sh;
	getchar();
	cin >> sh1;
	int length = sh.size();
	for (int i = 0; i < length; ++i)
	{
		if (sh[i] != sh1[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}