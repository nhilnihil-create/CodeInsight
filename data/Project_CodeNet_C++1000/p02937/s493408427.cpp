#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

signed main(){
	string s, t; cin >> s >> t;
	vector<vector<ll> > data(26);
	vector<int> cs(26, 0), ct(26, 0);
	ll n = s.size(), m = t.size();
	for(ll i = 0; i < n; i++) data[s[i] - 'a'].push_back(i + 1), cs[s[i] - 'a']++;
	for(int i = 0; i < m; i++) ct[t[i] - 'a']++;
	for(ll i = 0; i < 26; i++){
		if(cs[i] == 0 && ct[i] != 0){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 0; i < 26; i++) data[i].push_back(INF);
	
	ll ans = 0, now = 0;
	for(ll i = 0; i < m; i++){
		ll num = t[i] - 'a';
		ll next = *upper_bound(data[num].begin(), data[num].end(), now);
		if(next == INF) ans += n - now + data[num][0], now = data[num][0];
		else ans += next - now, now = next;
	}
	cout << ans << endl;
}