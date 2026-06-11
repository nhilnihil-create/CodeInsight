#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<n; i++)

ll MOD = 1e9+7;

ll m_pow(ll p, ll n){
	if(n==0) return 1;
  	else if(n%2){
    	ll now = m_pow(p,(n-1)/2);
      	return (now*now%MOD)*p%MOD;
    }
  	else{
		ll now = m_pow(p,n/2);
      	return now*now%MOD;
    }
}
  
ll m_comb(ll n, ll k){
	vector<ll> fact(k+1);
  	fact[0] = 1;
  	rep(i,k) fact[i+1] = fact[i]*(i+1)%MOD;
  	ll now = 1;
  	for(ll i=n; i>n-k; --i) now = now*i%MOD;
  	return now*m_pow(fact[k],MOD-2)%MOD;
}
  
int main(){
  	ll n, a, b;
  	cin >> n >> a >> b;
  	ll ans = 2*MOD + m_pow(2,n)-1-m_comb(n,a)-m_comb(n,b);
    ans %= MOD;
    cout << ans << endl;
  	return 0;
}