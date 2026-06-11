/*input

*/

#include <bits/stdc++.h>
#include <unistd.h>

#define rep(i,j,n) for(i=j;i<n;i++)
#define repi(i,j,n) for(i=j;i>n;i--)
#define inf 1e18
#define M 1000000007
#define pie 3.141592653589793238
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define UQ(x) (x).resize(distance((x).begin(),unique(x.begin(),x.end())))

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd64(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll a,ll m,ll mod){
	ll ans=1;
	while(m){
		if(m%2) ans*=a, ans%=(mod);
		a=(a*a)%(mod);
		m>>=1;
	}
	return ans;
}


void init(ll* a,ll n,ll val){
	for(ll i=0;i<n;i++)
		a[i]=val;
}

void solve(){
	ll i,j,_;
	ll n,k;
	cin>>n>>k;
	ll a[n];
	rep(i,0,n) cin>>a[i];
	ll l = 1, r = 1e9+1, ans = r;
	while(l <= r) {
		ll mid = (l+r) / 2;
		ll now = 0;
		rep(i,0,n) {
			now += a[i]/mid;
			if(a[i]%mid == 0) now--;
		}
		if(now > k) {
			l = mid + 1;
		}else {
			r = mid - 1;
			ans = min(ans, mid);
		}
	} 
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	ll T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


