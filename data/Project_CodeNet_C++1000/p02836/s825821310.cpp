#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int length = s.size();
	int ans = 0;
	for (int i = 0, j = length - 1; i < length / 2; ++i, j--)
	{
		if (s[i] != s[j])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}