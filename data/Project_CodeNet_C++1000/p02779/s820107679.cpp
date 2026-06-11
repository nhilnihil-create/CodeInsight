#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		mp[a]++;
	}
	string ans = "NO";
	if (mp.size() == n) ans = "YES";
	cout << ans << endl;
    return 0;
}