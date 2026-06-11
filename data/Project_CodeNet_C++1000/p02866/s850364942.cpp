#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=998244353;
const ll LINF=1LL<<60;
const int INF=1<<30;

//繰り返し二乗法
ll mod_pow(ll x,ll n){
	ll res = 1;
	while(n > 0){
		if(n & 1){
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main(){
	ll n;cin>>n;
	vector<ll> d(n);
	for(ll i = 0; i < n; i++) {
		cin>>d[i];
		if (i != 0 && d[i] == 0){
			cout << 0 << endl;
			return 0;
		}
	}
	if (d[0] !=  0){
		cout << 0 << endl;
		return 0;
	}
	vector<ll> cnt(n,0);
	for(ll i = 0; i < n; i++) {
		cnt[d[i]]++;
	}
	ll l;
	for(ll i = 1; i < n; i++) {
		if (cnt[i] == 0){
			l = i;
			for(ll j = i + 1; j < n; j++) {
				if (cnt[j] != 0){
					cout << 0 << endl;
					return 0;
				}
				break;
			}
		}
	}
	ll ans = 1;
	for(ll i = 1; i < min(l,n); i++) {
		ans *= mod_pow(cnt[i - 1] % mod,cnt[i]);
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}