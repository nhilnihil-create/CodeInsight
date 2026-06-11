#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int ll

signed main ()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	int ans = min(n % (a + b), a);
	ans += ((n / (a + b)) * a);
	cout << ans << endl;
	return 0;

}
