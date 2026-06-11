/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const ll mod = 1e9+7,M = 1e6+1;
vector <ll> fact(M);

void precalc(){
	fact[0] = 1;
	for(ll i=1;i<M;i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
}

ll modpow(ll x,ll n){
	if(n == 0) return 1%mod;
	ll u = modpow(x,n/2);
	u = (u*u)%mod;
	if(n&1) u = (u*x)%mod;
	return u;
}

ll inverse(ll n){
	return modpow(n,mod-2);
}

ll BC(ll n,ll k){
	return (((fact[n]*inverse(fact[n-k]))%mod)*inverse(fact[k]))%mod;
}

void solve(){
	ll n;
	cin >> n;
	ll i = 1;
	ll ans = 0;
	while(true){
		if(3*i>n) break;
		ans+=BC(n-2*i-1,i-1);
		ans%=mod;
		i++;
	}
	cout << ans << endl;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	precalc();
	int z;
	z = 1;
	//cin >> z;
	for(int z1=1;z1<=z;z1++){
		solve();
	}
	return 0;
}
