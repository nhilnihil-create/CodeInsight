#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a = {0, 300000, 200000, 100000};

	int x, y;
	cin >> x >> y;

	int ans = 0;

	if (x <= 3)
	{
		ans += a[x];
	}
	if (y <= 3)
	{
		ans += a[y];
	}

	if (x == 1 && y == 1)
	{
		ans += 400000;
	}

	cout << ans << endl;

	return 0;
}
