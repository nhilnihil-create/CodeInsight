#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define F first
#define S second

#define ONLINE_JUDGE 1

using namespace std;

const int mod = 1e9+7;

ll pwr(ll a, ll n){
	if(n==0) return 1;
	ll q = pwr(a,n / 2);
	q = q * q % mod;
	if(n&1) 
		q = q * a % mod;
	return q;
}

void solve(){
	int n,k;
	cin >> n >> k;
	ll res = 0;
	vector<ll> cnt(k+1);
	for(int i = k; i >= 1; i--){
		cnt[i] = pwr(k / i,n);
		for(int j = 2 * i; j <= k; j+=i){
			cnt[i] -= cnt[j];
			cnt[i]%=mod;
		}
		res = (res + i * cnt[i]) % mod;
	}
	cout << (res + mod)%mod << "\n";
}
int main(){
	#ifndef ONLINE_JUDGE	
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);		
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}