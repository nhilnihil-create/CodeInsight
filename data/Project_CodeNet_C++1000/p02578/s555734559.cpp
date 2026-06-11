#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define forn(i,n) for(int i=0;i<n;i++)
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)



void solve() {
	int n; cin >> n;
	int a[n];
	forn(i, n)cin >> a[i];
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{	if (a[i - 1] > a[i]) {
			ans += (a[i - 1] - a[i]);
			a[i] = a[i] + (a[i - 1] - a[i]);
		}
	}

	cout << ans << endl;
}







int32_t main() {

	fastio;

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// int t; cin >> t;
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}

