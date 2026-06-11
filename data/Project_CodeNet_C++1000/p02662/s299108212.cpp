#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
ll dp[3005][3005];
ll n,s;
ll a[3005];
const ll mod = 998244353;
ll qpow(ll a, ll b, ll m){
	if(b == 0)
		return 1;
	else if(b % 2 == 1)
		return a * qpow(a, b - 1, m) % m;
	else{
		ll num = qpow(a, b/2, m) % m;	
		return num * num % m;
	}
}
const ll inv2 = (mod+1) / 2;
int main(){
	cin>>n;
	cin>>s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	dp[0][0] = qpow(2,n,mod);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			(dp[i][j] += dp[i-1][j]) %= mod;
			if(j>=a[i]) {
				(dp[i][j] += dp[i-1][j-a[i]] * inv2) %= mod;
			}
		}
	}
	cout<<dp[n][s]%mod<<endl;
	return 0;
}