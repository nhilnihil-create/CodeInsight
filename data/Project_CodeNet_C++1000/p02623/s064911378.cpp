#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t = 1;
	// cin>>t;

	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;

		vector<ll> a(n),b(m);
		ll left = k;
		for(ll i=0;i<n;++i) cin>>a[i];
		for(ll i=0;i<m;++i) {cin>>b[i]; if(i!=0) {b[i] += b[i-1];}}

		ll i = 0;
		for(;i<n;++i){
			if(left >= a[i]) {left -= a[i];}
			else break;
		}
		--i;

		ll ans = i+1;
		while(1){
			ll x = upper_bound(b.begin(),b.end(),left) - b.begin();
			ans = max(ans , i+1 + x );
			if(i >=0 ){
				left += a[i];
				--i;
			}

			if(i == -1){
				x = upper_bound(b.begin(),b.end(),left) - b.begin();
				ans = max( ans, i+1+x);
				break;
			}

		}

		cout<<ans<<"\n";
	}

	return 0;

}