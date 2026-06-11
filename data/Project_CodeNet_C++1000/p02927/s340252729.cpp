#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int m, d, cnt;
	int d_1, d_10;
	cin >> m >> d;
	cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 20; j <= d; j++)
		{
			d_10 = j / 10;
			d_1 = j % 10;
			if (d_1 >= 2 && d_10 >= 2 && d_1 * d_10 == i)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
