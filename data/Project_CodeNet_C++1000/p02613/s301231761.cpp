#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	unordered_map<string, int> mp;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s]++;
	}
	cout << "AC x " << mp["AC"] << endl;
	cout << "WA x " << mp["WA"] << endl;
	cout << "TLE x " << mp["TLE"] << endl;
	cout << "RE x " << mp["RE"] << endl;
	return 0;
}