#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
const ll MOD = 1e9+7;

ll fact[N];
ll infact[N];

ll powermod(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b&1){
			ret *= a;
			ret %= MOD;
		}
		b/=2;
		a *= a;
		a %= MOD;
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	
	
	int n;
	cin>>n;
	fact[0] = 1;
	infact[0] = powermod(1,MOD-2);
	for(int i=1;i<=n;i++){
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
		infact[i] = powermod(fact[i],MOD-2);
	}
	
	ll ans = 0;
	
	for(int i=1;i<=n;i++){
		int t = 3*i;
		if(t > n)break;
		//cout<<i<<" "<<t<<" "<<n-t<<" "<<i-1<<" "<<fact[n-t]<<endl;
		ll tmp = fact[n-t+(i-1)]*infact[i-1];
		tmp %= MOD;
		tmp *= infact[(n-t)];
		tmp %= MOD;
		ans += tmp;
		ans %= MOD;
	}
	
	cout<<ans;
	
	return 0;
}

