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

	string s;
	ll k;
	cin >> s >> k;
	ll n = s.size(),ans = 0,memo = 1;
	ll pre_cnt = 1,suf_cnt = 1;



	



	

	rep(i,1,n){
		if(s[0] == s[i] && s[i] == s[i-1]) pre_cnt++;
		else break;
	}

	repr(i,0,n-1){
		if(s[n-1] == s[i] && s[i] == s[i+1]) suf_cnt++;
		else break;
	}

	
	if(pre_cnt == n){
		cout << k*n / 2 << endl;
		return 0;
	}

	rep(i,pre_cnt,n-suf_cnt){
		if(s[i] != s[i+1]){
			ans += memo / 2;
			memo = 1;
		}
		else memo++;
	}
	
	ans += memo / 2;
	ans *= k;
	
	if(s[0] == s[n-1]) ans += (k-1)*((pre_cnt+suf_cnt)/2);
	else ans += (k-1)*(pre_cnt/2+suf_cnt/2);
	ans += pre_cnt/2 + suf_cnt/2;

	cout << ans << endl;

    return 0;
}