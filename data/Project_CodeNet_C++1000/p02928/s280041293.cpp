#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double
#define rep(i, x, n, j) for(int i=x;i<(int)n;i+=j)
#define F first
#define S second
#define per(i, x, n, j) for(int i=(int)n-1;i>=0;i-=j)
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()

const int N = 2000100;
const ll MOD = 1e9+7;
const ll inf = 1e18+5;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int _;

ll fxn(ll n){
	return (((n-1)*n)/2)%MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k; cin >> n >> k;
	ll a[n];
	rep(i,0,n,1) cin >> a[i];
	vector<ll> b(n);
	for(int i=0; i<n; ++i){
		ll counter=0;
		for(int j=i+1; j<n; ++j){
			if(a[j]<a[i]) ++counter;
		}
		b[i]=counter;
	}

	vector<ll> c(n);
	for(int i=0; i<n; ++i){
		ll counter=0;
		for(int j=0; j<n; ++j){
			if(a[j]<a[i]) ++counter;
		}
		c[i]=counter;
	}

	ll ans = 0;
	rep(i,0,n,1){
		ans += ((c[i]*fxn(k))%MOD)+((b[i]*k)%MOD);
		ans %= MOD;
	}
	cout << ans << endl;
}
