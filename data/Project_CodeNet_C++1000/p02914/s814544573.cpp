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

ll a[100100];

int main(void){
	int n,i,j,r=0;
	ll s=0ll,ans=0ll;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
		s ^= a[i];
	}
	for(i=0; i<n; ++i){
		a[i] &= ~s;
	}
	for(j=59; j>=0; --j){
		for(i=r; i<n; ++i){
			if(a[i]&(1ll<<j)){
				break;
			}
		}
		if(i==n){
			continue;
		}
		if(i>r){
			a[r] ^= a[i];
		}
		for(i=r+1; i<n; ++i){
			if(a[i]&(1ll<<j)){
				a[i] ^= a[r];
			}
		}
		++r;
	}
	for(i=0; i<n; ++i){
		ans = max(ans,ans^a[i]);
	}
	ans <<= 1;
	ans += s;
	cout << ans << endl;
	return 0;
}
