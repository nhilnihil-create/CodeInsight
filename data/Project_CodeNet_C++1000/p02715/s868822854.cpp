#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll power(ll a,ll b){
	return b ? power(a*a%mod,b/2)*(b%2?a:1)%mod : 1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll dp[k+1],ans=0;
    for(ll i=k; i>=1; i--){
        dp[i]=power(k/i,n);
        for(ll j=2*i ; j<=k; j+=i) dp[i]-= dp[j];
        ans=(ans + i*dp[i] % mod) % mod;
    }
    cout<<(ans+mod)%mod;
    return 0;
}