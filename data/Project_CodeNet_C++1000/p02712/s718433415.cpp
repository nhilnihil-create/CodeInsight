#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a; cin >> a;
	long long int sum = 0;
	for (int i = 1; i <= a; ++i)
	{
		if (i % 5 == 0 || i % 3 == 0)
		{
			sum += 0;
		}
		else
			sum += i;
	}
	cout << sum << endl;
	return 0;
}