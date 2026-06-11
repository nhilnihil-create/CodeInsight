#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	if ((a == 1 || b == 1) && (b == 2 || a == 2))
	{
		cout << 3 << endl;
	}
	else if ((a == 1 || b == 1) && (b == 3 || a == 3))
	{
		cout << 2 << endl;
	}
	else if ((a == 2 || b == 2) && (a == 3 || b == 3))
	{
		cout << 1 << endl;
	}
	return 0;
}