#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int maxn=2e5+10;
int f[maxn];
int q(int a, int b){
	int ans = 1;
	while(b){
		if(b&1)ans = 1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ll ans, n, k;
	cin >> n >> k;
	ans=0;
	for(ll i=k;i>=1;i--){
		f[i]=q(k/i,n);
		for(ll j=2*i;j<=k;j+=i){
			f[i]=(f[i]-f[j]+mod)%mod;
		}
	}
	for(ll i=1;i<=k;i++){
		ans+=i*f[i]%mod;
		ans%=mod;
	}
	cout << ans << endl;
}