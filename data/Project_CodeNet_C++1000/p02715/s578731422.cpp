#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
int n, k;
long long a[100002];
long long ans=0;

long long modpow(long long x, int y){
	long long ret=1;
	for (;y>0;y>>=1){
		if (y&1){
			ret*=x;
			ret%=mod;
		}
		x*=x;
		x%=mod;
	}
	return ret;
}

int main(){
	cin >> n >> k;
	for (int i=k;i>0;i--){
		a[i]=modpow(k/i,n);
		for (int j=i+i;j<=k;j+=i){
			a[i]-=a[j];
			a[i]%=mod;
			a[i]+=mod;
			a[i]%=mod;
		}
		ans+=(i*a[i])%mod;
		ans%=mod;
	}
	cout << ans << "\n";
}	