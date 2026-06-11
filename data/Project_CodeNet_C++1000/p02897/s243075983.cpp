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

	int n; cin >> n;
	long double sumo = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 != 0)
		{
			sumo++;
		}
	}
	printf("%.10Lf\n", sumo / n);
	return 0;
}