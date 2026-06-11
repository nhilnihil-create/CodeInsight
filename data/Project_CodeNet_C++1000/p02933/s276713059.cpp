#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a; cin >> a;
	string sh; cin >> sh;
	if (a < 3200)
	{
		cout << "red" << endl;
	}
	else
	{
		cout << sh << endl;
	}
	return 0;
}