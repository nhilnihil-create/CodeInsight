#include "bits/stdc++.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Pll;
typedef pair<P,P> PP;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define repr(i,a,n) for(ll i = n-1;i >= a;i--)
#define LINF (ll)1e17
#define INF 1e9
#define MOD (ll)1e9+7
#define sMOD 1e5
#define fs first
#define sc second
#define setprecision(d) cout << fixed << setprecision(d);

ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
	
}

ll lcm(ll a,ll b){
	return a * b / gcd(a,b);
}


signed main(){

	ll n,m = 0,k,ans = 0;
	cin >> n >> k;

	ll a[n];
	
	ll memo = 0;
	rep(i,0,n){
		cin >> a[i];
		rep(j,0,i){
			if(a[j] > a[i]) memo++;
		}
	}
	


	sort(a,a+n);


	rep(i,0,n){
		rep(j,0,n){
			if(a[i] < a[j]) m++;
		}
	}
	

	
	
	//memo2 = m*k*(k-1)/4;

	ll memo2 = k;
	memo2 *= (k-1);
	memo2 /= 2;
	memo2 %= (ll)(1e9+7);

	memo2 *= m;
	memo2 %= (ll)(1e9+7);
	


	ans += memo2;
	ans %= (ll)(1e9+7);
	ans += memo*k;
	ans %= (ll)(1e9+7);
	

	cout << ans << endl;

	


    return 0;
}