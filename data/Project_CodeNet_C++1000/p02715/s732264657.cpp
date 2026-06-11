#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll modi = 1e9+7;
ll binpow(ll a,ll b){
	ll res  =1;
	while(b>0){
		if(b&1)
			res = res*a%modi;
		a= a*a%modi;
		b>>=1;
	}
	return res;
}

int main(){
	ll n,k;
	cin >> n >>k;
	ll dp[k+1];
	memset(dp,0,sizeof(dp));
	for(ll i =k;i>0;--i){
		ll to_make = k/i;
		dp[i] = binpow(to_make,n);
		for(int j = 2;i*j<=k;j++){
			dp[i]-=dp[i*j];
		}
	}

	ll ans =0;
	for(int i =1;i<=k;i++){
		ans = (ans + i*dp[i]%modi)%modi;
	}
	cout << ans << endl;

}