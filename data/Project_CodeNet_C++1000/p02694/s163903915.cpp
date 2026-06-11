#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int a, sum = 100, year = 0; cin >> a;
	while (sum < a)
	{
		sum = sum + (sum / 100);
		year++;
	}
	cout << year << endl;
	return 0;
}