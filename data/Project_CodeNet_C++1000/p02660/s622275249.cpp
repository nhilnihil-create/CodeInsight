#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

vector<pair<ll,ll>> factorize(ll n){
	vector<pair<ll,ll>> res;
	for (ll i = 2; i*i <= n; ++i) {
		if(n % i)continue;
		res.emplace_back(i,0);
		while(n % i == 0){
			res.back().second++;
			n /= i;
		}
	}
	if(n > 1){
		res.emplace_back(n,1);
	}
	return res;
}

int main(){
	ll n;
	cin >> n;
	auto v = factorize(n);
	ll ans = 0;
	rep(i, v.size()){
		ll count = 0;
		while(1){
			if((count+1)*count/2 > v[i].second){
				count--;
				break;
			}
			count++;
		}
		ans += count;
	}
	cout << ans << endl;
    return 0;
}