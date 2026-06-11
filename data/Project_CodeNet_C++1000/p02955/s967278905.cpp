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
	
	ll n, k;
	cin >> n >> k;
	ll a[n];
	ll sm = 0;
	zep(i, 0, n){
		cin >> a[i];
		sm += a[i];
	}
	
	vector<P> v;
	ll all = 1;
	for(ll i = 2; i*i <= 5e8; i++){
		ll cnt = 0;
		while(sm%i == 0){
			sm /= i;
			cnt++;
		}
		if(cnt > 0){
			v.push_back(P(i, cnt));
			all *= cnt+1;
		}
	}
	if(sm > 1){
		v.push_back(P(sm, 1));
		all *= 2;
	}
	//print(all)
	ll ans = 1;
	zep(j, 1, all){
		ll tmp = j;
		ll mod = 1;
		zep(k, 0, v.size()){
			mod *= pow(v[k].first, tmp%(v[k].second+1));
			tmp /= v[k].second+1;
		}
		
		ll b[n];
		zep(i, 0, n){
			b[i] = a[i]%mod;
		}
		sort(b, b+n);
		
		ll l = 0;
		ll li = 0;
		ll r = 0;
		ll ri = n-1;
		while(li <= ri){
			if(l < r){
				l += b[li];
				li++;
			}
			else{
				if(r < l){
					r += mod-b[ri];
					ri--;
				}
				else{
					if(b[li] < mod-b[ri]){
						l += b[li];
						li++;
					}
					else{
						r += mod-b[ri];
						ri--;
					}
				}
			}
		}
		if(max(l, r) <= k){
			ans = max(mod, ans);
		}
	}
	print(ans)
	return 0;
}