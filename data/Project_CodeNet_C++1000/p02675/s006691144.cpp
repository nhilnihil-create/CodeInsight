#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a; cin >> a;
	if (a % 10 == 2 || a % 10 == 4 || a % 10 == 5 || a % 10 == 7 || a % 10 == 9)
	{
		cout << "hon" << endl;
	}
	else if (a % 10 == 0 || a % 10 == 1 || a % 10 == 6 || a % 10 == 8)
	{
		cout << "pon" << endl;
	}
	else
	{
		cout << "bon" << endl;
	}
	return 0;
}