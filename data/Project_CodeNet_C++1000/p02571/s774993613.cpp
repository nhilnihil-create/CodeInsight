#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	string big, little;
	cin >> big >> little;
	int ans = 1e9;
	int max_cnt = big.size() - little.size() + 1;
	for (int i = 0; i < max_cnt; i++)
	{
		int tmp = 0;
		for (int j = 0; j < little.size(); j++) tmp += (big[i + j] != little[j]);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return (0);
}
