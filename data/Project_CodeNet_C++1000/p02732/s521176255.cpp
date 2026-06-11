#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {
	int n;
	scanf("%d", &n);
	vector<ll> v(n + 1);
	unordered_map<ll, ll> mp;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
		mp[v[i]]++;
	}
	ll ans = 0;
	for (auto c : mp)
		ans += c.second * (c.second - 1) / 2;
	for (int i = 1; i <= n; i++) {
		ans -= mp[v[i]] * (mp[v[i]] - 1) / 2;
		mp[v[i]]--;
		ans += mp[v[i]] * (mp[v[i]] - 1) / 2;
		printf("%lld\n", ans);
		ans -= mp[v[i]] * (mp[v[i]] - 1) / 2;
		mp[v[i]]++;
		ans += mp[v[i]] * (mp[v[i]] - 1) / 2;
	}
}
