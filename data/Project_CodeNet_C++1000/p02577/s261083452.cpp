#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define forn(i,n) for(int i=1;i<n+1;i++)
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)



void solve() {
	string s;
	cin >> s;

	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}

	if (sum % 9 == 0)cout << "Yes" << endl;
	else
		cout << "No" << endl;

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

