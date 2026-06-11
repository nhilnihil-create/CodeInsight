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
	ll n,memo = 0;
	cin >> n;
	ll a[n];
	rep(i,0,n){
		cin >> a[i];

		memo = memo^a[i];
	}

	if(memo == 0)cout << "Yes" << endl;
	else cout << "No" << endl;

    return 0;
}