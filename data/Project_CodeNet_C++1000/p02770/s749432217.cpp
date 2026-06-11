#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll d[5555],f[5555];

int main(void){
	int k,q,i,j;
	ll n,x,m,ans;
	cin >> k >> q;
	for(i=0; i<k; ++i){
		cin >> d[i];
	}
	for(i=0; i<q; ++i){
		cin >> n >> x >> m; --n;
		x %= m; ans = n;
		for(j=0; j<k; ++j){
			f[j+1] = f[j]+d[j]%m;
			if(!(d[j]%m)){
				ans -= (n/k+(j<n%k));
			}
		}
		ans -= (x+f[k]*(n/k)+f[n%k])/m;
		cout << ans << endl;
	}
	return 0;
}
