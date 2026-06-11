		#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back

using namespace std;

using ll = long long;
using ld = long double;

const ll inf = LONG_LONG_MAX;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = (res * a)%mod;
        }
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

signed main(){
	ll t;
	//cin >> t;
	t = 1;
	while(t--){
		ll n,k;
		cin >> n >> k;

		vector<ll>h(n+1);

		for(ll i=1;i<=n;i++){
			cin >> h[i];
		}

		vector<ll>adj[n+1];

		for(ll i=1;i<=k;i++){
			ll a,b;
			cin >> a >> b;

			adj[a].pb(b);
			adj[b].pb(a);
		}

		ll ans = 0;

		for(ll i=1;i<=n;i++){
			ll x = h[i];

			ll cnt = 0;
			//cout << x ;
			for(ll j=0;j<adj[i].size();j++){
				if(x > h[adj[i][j]]){
					cnt++;
				}
				//cout << adj[i][j] << " ";
			}
			//cout << "\n";
			if(cnt == adj[i].size()){
				ans++;
			}
			//cout << ans << "\n";
		}

		cout << ans << "\n";
	}
	return 0;
}