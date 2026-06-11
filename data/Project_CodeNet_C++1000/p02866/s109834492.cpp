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
	ll n,memo = 0,ans = 1;
	cin >> n;
	ll d[n];
	ll cnt[n] = {};

	rep(i,0,n){
		cin >> d[i];
		cnt[d[i]]++;

		memo = max(d[i],memo);

		if(d[0] != 0 || (d[i] == 0 && i != 0)){
			cout << 0 << endl;
			return 0;
		}
	}

	rep(i,0,memo){
		rep(j,0,cnt[i+1]){
			ans *= cnt[i];
			ans %= 998244353;
		}
	}

	cout << ans << endl;

	
    return 0;
}