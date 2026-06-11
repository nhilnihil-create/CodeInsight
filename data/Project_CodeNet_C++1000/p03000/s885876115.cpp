#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;


void solve()
{
	int n, x;
	cin >> n >> x;
	int l[n];
	for (int i = 0; i < n; i++)
		cin >> l[i];
	int ans =0 ;
	if (ans <= x)
		ans++;
	int curr = 0;
	for (int i =1 ; i <= n; i++)
	{
		curr = curr + l[i - 1];
		if (curr <= x)
			ans++;
	}
	cout << ans;
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}


