#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b; cin >> a >> b;
	long double sum = ((a + b) * 1.0) / 2;
	if (sum == (int)sum)
	{
		cout << (int)sum << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;
	return 0;
}