#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}	ll sum2[100010]={};
int main() {
	ll n,k;
	cin>>n>>k;
	ll ans=0;

	for(ll i=1;i<=k;i++){
		ll up=k/i;
//		ll down=up-1;
		ll l=modpow(up, n, 1000000007);
//		ll r=modpow(down,n,1000000007);
		ll sum=(l);
		sum%=inf;
		sum2[i]=sum;
	}
	for(ll i=k;i>=1;i--){
		ll cnt=sum2[i];
		ll j=2;
		while(i*j<=k){
			cnt-=sum2[i*j];
			j++;
			while(cnt<0){
				cnt+=inf;
			}
		}
		sum2[i]=cnt;
		ans+=sum2[i]*i;
		ans%=inf;
	}
	cout <<ans;
	// your code goes here
	return 0;
}