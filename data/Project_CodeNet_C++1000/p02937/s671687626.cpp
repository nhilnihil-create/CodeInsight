 // In the name of GOD
 
#include <bits/stdc++.h>
#define ll long long
#define pp pair <int, int>
using namespace std;
const int N = 2e5 + 10, MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	string s;
	string t;
	cin >> s >> t;
	map <char, vector <int>> mp;
	int i = 0;
	for (char c : s) {
		mp[c].push_back(i);
		++i;
	}

	int id = -1;
	ll freq = 0;
	for (int i = 0; i < t.length(); ++i) {
		char c = t[i];
		if (mp[c].empty()) {
			cout << -1;
			return;
		}

		if (upper_bound(mp[c].begin(), mp[c].end(), id) == mp[c].end()) {
			freq++;
			id = mp[c][0];
		}
		else
			id = mp[c][upper_bound(mp[c].begin(), mp[c].end(), id) - mp[c].begin()];
		// cout << freq << " " << id << "\n";
	}
	ll ans = 1LL*(int)s.length() * freq + id + 1;
	cout << ans;
}

int main () {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve();
    }
}                                  