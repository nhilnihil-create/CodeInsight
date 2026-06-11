#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k, display_total, inner_rating; cin >> k >> display_total;
	if (k >= 10)
	{
		cout << display_total << endl;
	}
	else
	{
		cout << display_total + (100 * (10 - k));
	}
	return 0;
}
