#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh, sh1;
	cin >> sh >> sh1;
	long long int ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (sh[i] == sh1[i])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}