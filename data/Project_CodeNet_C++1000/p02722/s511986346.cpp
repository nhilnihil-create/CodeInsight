#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

vector<pair<ll,ll>> factorize(ll n){
	vector<pair<ll,ll>> res;
	for (ll i = 2; i*i <= n; ++i) {
		if(n % i) continue;
		res.emplace_back(i,0);
		while(n % i == 0){
			n /= i;
			res.back().second++;
		}
	}
	if(n != 1) res.emplace_back(n,1);
	return res;
}

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 2; i * i <= n; ++i) {
		ll temp = n;
		if(temp % i) continue;
		while(temp % i == 0){
			temp /= i;
		}
		if(temp % i == 1) ans++;
	}
	auto v = factorize(n-1);
	ll yakusuu = 1;
	rep(i,v.size()){
		yakusuu *= v[i].second + 1;
	}
	yakusuu--;
	ans += yakusuu + 1;
	cout << ans << endl;
	return 0;
}

