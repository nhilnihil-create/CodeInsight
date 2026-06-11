#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int a;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 5; i++)
	{
		cin >> a;
		if (a == 0)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
//10-09-2020 17:26:55