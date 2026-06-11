#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

/*
N/(26^k)が欲しい
たかだか12個
*/

int	main(void)
{
	long long n;
	cin >> n;
	string ans = "";
	for (int i = 0; i < 13; i++)
	{
		if (!n) break;
		ans += char((n % 26 - 1 + 26) % 26 + 'a');
		n -= (n % 26 - 1 + 26) % 26;
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return (0);
}