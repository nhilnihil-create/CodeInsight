#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vl>
#define vvi vector<vi>
#define pb push_back
#define P pair<ll,ll>
#define mp make_pair
#define F first
#define S second
#define rep(i,n) for(ll i=0; i<n; i++)
#define Sort(v) sort(v.begin(), v.end())
#define all(v) v.begin(),v.end()

ll mo = 1000000007;
ll MO = 998244353;

ll modpower(ll a, ll b, ll mod){
	ll ans = 1;
	if(b == 0){
		return 1;
	}
	if(b%2 == 1){
		ans = a;
	}
	ll x = modpower(a,b/2,mod)%mod;
	ans *= (x*x)%mod;
	ans %= mod;
	return ans;
}

void pri(vl a){
	for(auto i:a)
		cout<<i<<" ";
	cout<<endl;
}

//-------------------------------------------------------------------------------
ll n,k;
bool foo(ll m, vl &a){
	ll val = 0;
	rep(i,n){
		ll x = a[i]/m;
		if(a[i]%m == 0) x--;
		val += x;
	}
	if(val>k) return false;
	return true;
}

void solve(){
	cin>>n>>k;
	vl a(n);
	rep(i,n) cin>>a[i];
	ll l = 1, r = 1e9;
	while(l<r){
		ll m = (l+r)/2;
		if(foo(m, a)){
			r = m; continue;
		}
		else{
			l = m+1; continue;
		}
	}
	cout<<r<<endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int nt = 1;
	// cin>>nt;
	while(nt--){
		solve();
	}
	return 0;
}