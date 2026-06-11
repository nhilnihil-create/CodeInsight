#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll M = 1000000007;
//べき乗高速化
ll mpow(ll x, ll n){
	ll ans = 1;
	while(n != 0){
		if (n&1) ans = ans * x % M;
		x = x*x % M;
		n  = n >> 1;
	}
	return ans;
}


int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> count(k+1,0);
	ll ans = 0;
	for (int i = k; i >= 1 ; --i) {
		ll x = k/i;
		ll temp = mpow(x, n);
		for (int j = 2; j <= k; ++j) {
			if(i*j > k) break;
			temp -= count[i*j];
		}
		count[i] = temp;
	}
	REP(i,k){
		ans += i*count[i] % M;
	}
	cout << ans % M << endl;
    return 0;
}

