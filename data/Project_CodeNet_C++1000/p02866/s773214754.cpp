#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const ll M = 998244353;

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
	ll N;
	cin >> N;
	vector<ll> d(N);
	ll dmax = 0;
	rep(i,N){
		cin >> d[i];
		dmax = max(dmax, d[i]);
		if(i != 0 && d[i] == 0){
			cout << 0 << endl;
			return 0;
		}
	}
	
	map<ll,ll> count;
	
	rep(i,N){
		count[d[i]]++;
	}
	
	bool exist = true;
	rep(i,dmax+1){
		if(count[i] == 0) exist = false;
	}
	
	if(!exist){
		cout << 0 << endl;
		return 0;
	}
	
	ll ans = 1;
	
	REP(i,dmax-1){
		ans *= mpow(count[i], count[i+1]);
		ans %= M;
	}
	
	cout << ans<< endl;
	
	return 0;
}

