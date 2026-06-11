#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int a, b, c, k;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c >> k;
	if (a >= k)
		cout << k;
	else if ((a + b) >= k)
		cout << a;
	else
		cout << a - (k - (a + b));
	return 0;
}
//11-09-2020 10:07:44