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
	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (l[i] == l[j] || l[j] == l[k] || l[k] == l[i]) continue;
				int l_max = max({l[i], l[j], l[k]});
				if (2 * l_max < (long long)l[i] + l[j] + l[k]) ans++;
			}
		}
	}
	cout << ans << endl;
	return (0);
}
