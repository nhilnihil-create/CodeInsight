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
    
ll solve(int k, int n){
	if(n > k - n){
		n = k -n;
	}
	ll num = 1, den = 1;
	for(int i=1; i <= n; i++){
		num *= (k - i + 1);
		den *= i;
		num %= mod;
		den %= mod;
	}	
	return (num * power(den, mod - 2, mod)) % mod;
}

int run_test(){
	int x, y;
	cin >> x >> y;
	if((x + y) % 3){
		cout << 0 << "\n";
		return 0;
	}
	if((2*x - y) < 0 || (2*y - x) < 0){
		cout << 0;
		return 0;
	}
	int k = (x + y)/3;
	int n = (2*x - y)/3;
	ll ans = solve(k, n);
	cout << ans;
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