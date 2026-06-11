#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int n, cnt;
	cin >> n;
	cnt = 0;
	for(int i = 1; i <= n / 2; i++)
	{
		int j = n - i;
		if (j != i) 
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
