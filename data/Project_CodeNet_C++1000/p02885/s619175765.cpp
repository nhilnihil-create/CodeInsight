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
	int sum = a - (2 * b);
	if (sum > 0)
	{
		cout << sum << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}