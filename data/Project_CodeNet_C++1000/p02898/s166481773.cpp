#include <bits/stdc++.h>
using namespace std;


#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, k; cin >> t >> k;
	int sum = 0;
	for (int i = 0; i < t; ++i)
	{
		int a;
		cin >> a;
		if (a >= k)
		{
			sum++;
		}
	}
	cout << sum << endl;
	return 0;

}