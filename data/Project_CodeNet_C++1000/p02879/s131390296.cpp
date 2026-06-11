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
	if (a / 10 == 0 && b / 10 == 0)
	{
		cout << a*b << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}