#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	if (s == "SUN")
	{
		cout << 7 << endl;
	}
	else if (s == "MON")
	{
		cout << 6 << endl;
	}
	else if (s == "TUE")
	{
		cout << 5 << endl;
	}
	else if (s == "WED")
	{
		cout << 4 << endl;
	}
	else if (s == "THU")
	{
		cout << 3 << endl;
	}
	else if (s == "FRI")
	{
		cout << 2 << endl;
	}
	else
		cout << 1 << endl;
	return 0;
}