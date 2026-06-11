#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k, x; cin >> k >> x;
	int end = x + k;
	for (int start = x - ( k - 1); start < end; start++)
	{
		cout << start << " ";
	}
	return 0;
}