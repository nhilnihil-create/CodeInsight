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
		ll n;
		cin>>n;

		ll ans = 0;
		for(ll i=1;i<=n;++i){
			ll m = n/i;
			m = (m*(m+1))/2;
			ans  += m*i;
		}

		cout<<ans<<'\n';
	}

	return 0;

}