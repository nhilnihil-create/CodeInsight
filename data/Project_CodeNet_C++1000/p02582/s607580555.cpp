#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	string s;
	cin >> s;
	int ans = 0;
	int tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		if (s[i] != 'R')
		{
			ans = max(ans, tmp);
			tmp = 0;
		}
		else tmp++;
	}
	ans = max(ans, tmp);
	cout << ans << endl;
	return (0);
}
