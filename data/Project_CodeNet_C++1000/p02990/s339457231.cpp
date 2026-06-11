#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
    
ll ncr(ll n,ll r){
	if(n < r) return 0;
	if(r > n-r){
		r = n-r;
	}
	ll num = 1, den = 1;
	for(int i=1; i<=r; i++){
		num = (num*(n - i + 1)) % mod;
		den = (den * i) % mod;
	}
	return (num * power(den ,mod - 2, mod))%mod;
}

int run_test(){
	ll n, k;
	cin >> n >> k;
	for(int i=1; i<=k; i++){
		ll ans = (ncr(n - k + 1, i) * ncr(k-1, i -  1)) % mod;
		cout << ans << "\n";
	}
	return 0;
}
    
int main(){
   FAST;
    ll t;
    t = 1;
     
    while(t--){
        run_test();
    }
}