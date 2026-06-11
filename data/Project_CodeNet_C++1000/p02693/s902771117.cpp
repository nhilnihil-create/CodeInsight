#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k, a, b; cin >> k >> a >> b;
	for (int i = 1; k * i <= b; ++i)
	{
		if (k * i >= a && k * i <= b)
		{
			cout << "OK" << endl;
			return 0;
		}
		else
			continue;
	}
	cout << "NG" << endl;

	return 0;
}