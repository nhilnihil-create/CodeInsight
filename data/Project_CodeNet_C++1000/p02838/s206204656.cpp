#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define sc second
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll ans, bit[65];

int main()
{
	ll n; scanf("%lld", &n);
	
	for(ll i = 1; i <= n; i++){
		ll inp; scanf("%lld", &inp);
		
		for(ll j = 0; j < 60; j++){
			if((1LL << j) & inp) bit[j]++;
		}
	}
	for(ll i = 0; i < 60; i++){
		ans = (ans + ( ( ((1LL << i) % mod) * bit[i]) % mod * (n - bit[i])) % mod) % mod;
	}
	printf("%lld\n", ans);
}