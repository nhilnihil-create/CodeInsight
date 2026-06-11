#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 0;

ll n, a[20], b, c;
vector<vector<ll>> x(20), y(20); 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		for(ll j = 0; j < a[i]; j++){
			cin >> b >> c;
			b--;
			x[i].pb(b), y[i].pb(c);
		}
	}
	ll ans = 0;
	for(ll i = 0; i < (1 << n); i++){
		ll cnt = 0, cek = 1;
		for(ll j = 0; j < n; j++){
			if(i & (1 << j)){
				cnt++;
				for(ll k = 0; k < a[j]; k++){
					if((i & (1ll << x[j][k]) && y[j][k])){
						continue;
					}
					else if((!(i & (1 << x[j][k])) && !(y[j][k]))){
						continue;
					}
					else{
						cek = 0;
						break;
					}
				}
			}
		}
		if(cek){
			ans = max(ans, cnt);
		}
	}
	cout << ans << '\n';				
}
