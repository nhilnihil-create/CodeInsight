#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define forn(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();


	int ans = INT_MAX;
	for (int st = 0; st <= (n - m); st++) {
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			if (s[i + st] != t[i])
				cnt++;
		}
		ans = min(ans, cnt);
	}

	cout << ans << endl;








}

int32_t main() {

	fastio;

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// int t; cin >> t;/
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}