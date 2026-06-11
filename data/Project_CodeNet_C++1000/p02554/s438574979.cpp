/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const ll mod = 1e9+7,M = 1e6+1;

ll modpow(ll x,ll n){
	if(n == 0) return 1%mod;
	ll u = modpow(x,n/2);
	u = (u*u)%mod;
	if(n&1) u = (u*x)%mod;
	return u;
}

void solve(){
	ll n;
	cin >> n;
	cout << (modpow(10,n)-2*modpow(9,n)+modpow(8,n)+10*mod)%mod << endl;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int z;
	z = 1;
	//cin >> z;
	for(int z1=1;z1<=z;z1++){
		solve();
	}
	return 0;
}
