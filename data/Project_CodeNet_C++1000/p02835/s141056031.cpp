#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 22)
	{
		cout << "bust" << endl;
	}
	else
		cout << "win" << endl;
	return 0;
}