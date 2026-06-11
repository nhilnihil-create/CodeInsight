#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a; cin >> a;
	long long int happiness = 0, x = 0, y = 0, z = 0;
	if (a / 500 > 0)
	{
		happiness = 1000 * (a / 500);
	}
	x = a % 500;
	if (x / 5 > 0)
	{
		happiness = happiness + (5 * (x / 5));
	}
	cout << happiness << endl;
	return 0;
}
