#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	ll x; cin>>x;
	ll ans = 0;
	for(ll i = 0; i<=2000000; i++){
		if((i * 500) > x) break;
		//~ cout<<i<<endl;
		ll n_500 = i, n_5 = (x - (i * 500)) / 5;
		ans = max(ans, (n_500 * 1000) + (n_5 * 5));
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin>>t;
	while(t--) solve();
	return 0;
}
