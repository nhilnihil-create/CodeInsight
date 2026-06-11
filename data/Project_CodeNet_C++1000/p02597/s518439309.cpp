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
	vector<char> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	int red_cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) red_cnt += (c[i] == 'R');
	for (int i = 0; i < red_cnt; i++) ans += (c[i] != 'R');
	cout << ans << endl;
	return (0);
}
