#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll k, q;
	cin >> k >> q;
	ll d[k], n[q], x[q], m[q];
	zep(j, 0, k){cin >> d[j];}
	zep(i, 0, q){cin >> n[i] >> x[i] >> m[i]; x[i] %= m[i];}
	
	zep(i, 0, q){
		ll dm[k];
		zep(j, 0, k){dm[j] = d[j]%m[i];}
		ll z[k];
		zep(j, 0, k){
			z[j] = (dm[j] == 0)? 1 : 0;
		}
		zep(j, 1, k){
			dm[j] += dm[j-1];
			z[j] += z[j-1];
		}
		
		ll sm = x[i]+((n[i]-1)/k)*dm[k-1];
		if((n[i]-1)%k > 0){sm += dm[(n[i]-1)%k-1];}
		ll ans = n[i]-1-sm/m[i]-((n[i]-1)/k)*z[k-1];
		if((n[i]-1)%k > 0){ans -= z[(n[i]-1)%k-1];}
		print(ans)
	}
	
	return 0;
}