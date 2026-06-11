#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int n, m;
	cin >> n >> m;
	n -= (n % 2 == 0);
	int start = 1;
	int end = n / 2;
	int cnt = 0;
	while (1)
	{
		if (start >= end - start + 1 || cnt == m) break;
		cout << start << " " << end - start + 1 << endl;
		start++; cnt++;
	}
	start = n / 2 + 1;
	end = n;
	while (1)
	{
		if (start >= end - start + (n / 2 + 1) || cnt == m) break;
		cout << start << " " << end - start + (n / 2 + 1) << endl;
		start++; cnt++;
	}
	return (0);
}
