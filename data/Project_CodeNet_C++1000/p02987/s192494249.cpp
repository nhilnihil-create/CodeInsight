#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh; cin >> sh;
	sort(sh.begin(), sh.end());
	if (sh[0] == sh[1] && sh[2] == sh[3] && sh[0] != sh[3])
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}