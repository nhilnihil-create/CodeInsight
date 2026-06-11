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
#define INF (int)1e9
#define MOD (ll)1e9+7
#define sMOD 1e5
#define fs first
#define sc second

ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
	
}



signed main(){
	ll n,ans = 0;
	cin >> n;
	ll t[n];
	string s[n],x;
	bool flag = false;
	
	rep(i,0,n){
		cin >> s[i] >> t[i];
	}
	cin >> x;
	
	
	rep(i,0,n){
		if(flag) ans += t[i];
		if(x == s[i]) flag = true;
	}
	
	cout << ans << endl;
	
    return 0;
}