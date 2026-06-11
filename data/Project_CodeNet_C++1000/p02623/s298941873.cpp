#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FASTIO;

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n + 1);
	vector<int> b(m + 1);

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;

		a[i] = x + a[i - 1];
		// cout << a[i] << " ";
	}
	// cout << endl;

	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;

		b[i] = x + b[i - 1];
		// cout << b[i] << " ";
	}

	// cout << endl;

	int ans = 0;

	for (int i = 0; i <= n; i++)
	{
		if (a[i] > k) break;

		int rem = k - a[i];
		int l = upper_bound(b.begin(), b.end(), rem) - b.begin();
		// cout << rem << " " << l - 1 << endl;

		ans = max(ans, i + l - 1);
	}

	cout << ans;
}