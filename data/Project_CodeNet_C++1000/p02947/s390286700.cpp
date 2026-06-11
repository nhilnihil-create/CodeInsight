#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	unordered_map<string, int> mp;
	while(n--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		mp[s]++;
	}
	ll total = 0;
	for(auto x: mp) {
		if(x.second == 1) {
			continue;
		}
		else {
			ll a = x.second;
			total += (a * (a - 1)) / 2;
		}
	}
	cout << total << "\n";

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}