#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector< string > ss(n);
	map< vector<ll>, ll> mp1;
	for (auto& e:ss) {
		vector<ll> freq(26);
		cin >> e;
		for(auto& f:e) {
			freq[(f-'a')]++;
		}
		mp1[freq]++;
	}
	ll ans = 0;
	for(auto& e:mp1) {
		if (e.second > 1) {
			ll v = e.second;
			ans += (v*(v-1))/2;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
