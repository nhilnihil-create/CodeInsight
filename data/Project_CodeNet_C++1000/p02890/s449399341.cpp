#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep0(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
	ll n; cin >> n;
	ll b[n+1] = {0};
	ll z, i, j;
	rep(i, n){
		cin >> z;
		b[z] += 1;
	}

	
	ll d[n+1] = {0};
	rep(i,n){
		d[b[i]] += 1;
	}

	ll dRuiseki[n+1] = {0}, dkRuiseki[n+1] = {0};
	rep(i, n) {
		dkRuiseki[i] += (dkRuiseki[i-1] + i*d[i]);
		dRuiseki[i] += dRuiseki[i-1] + d[i];
	}
	ll f[n+1];
	rep(i,n){
		f[i] =  (dkRuiseki[i] + i*(dRuiseki[n] - dRuiseki[i]))/i ;
	}

	ll ans[n+1] = {0};
	ll count = 1;
	rep(i, n){
		while(n+1-i <= f[count] && count < n+1){
			count++;
		}
		ans[n+1-i] = count-1;
	}

	rep(i, n) cout << ans[i] << endl;
	return 0;
}