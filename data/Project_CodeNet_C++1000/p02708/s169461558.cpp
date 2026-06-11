
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k;
	cin >> n >> k;
	long long mod=1000000007;
	long long ans=0;
	long long a[n+2];
	a[0]=0;
	for(long long i=1;i<=n+1;i++){
		a[i]=a[i-1]+i-1;
	}
	for(long long i=k;i<=n+1;i++){
		ans+=(((a[n+1]-a[n-i+1])-(a[i]-a[0])+1)%mod);
		ans=ans%mod;
	}
	cout << ans << endl;
}
