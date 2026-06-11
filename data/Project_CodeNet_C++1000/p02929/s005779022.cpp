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

int main(void){
	int n,cnt=0,i;
	ll ans=1ll,r=0ll;
	string s;
	cin >> n;
	cin >> s;
	for(i=0; i<n*2; ++i){
		if((s[i]=='W')^(r%2)){
			mul_mod(ans,r);
			--r;
		}else{
			++r;
			++cnt;
		}
		if(cnt>n || r<0 || r>n){
			ans = 0ll;
			break;
		}
	}
	if(r){
		ans = 0ll;
	}
	for(i=1; i<=n; ++i){
		mul_mod(ans,i);
	}
	cout << ans << endl;
	return 0;
}
