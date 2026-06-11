#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++) cin >> a[i];
	ll mod=1e9+7;
	ll ans=0;
	ll two_factor=1;
	for(int d=0;d<60;d++){
		ll even=0,odd=0;
		for(int i=0;i<n;i++){
			if(a[i]&(1LL<<d)) odd++;
			else even++;
		}
		ll add=(odd*even)%mod*two_factor%mod;
		ans=(ans+add)%mod;
		two_factor=(two_factor*2)%mod;
	}
	cout << ans%mod << endl;
}
