#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10; 
const int mod = 1e9+7;
long long b[N],c[N],d[N],a[N];
int main(){
	int n;
	cin>>n;
	a[1]=1;
	b[1]=1;
	c[1]=0;
	d[1]=8;
	for(int i=2;i<=n;i++){
		a[i]=(a[i-1]*9+d[i-1])%mod;
		b[i]=(b[i-1]*9+d[i-1])%mod;
		c[i]=(a[i-1]+b[i-1]+c[i-1]*10)%mod;
		d[i]=(d[i-1]*8)%mod; 
	//	printf("%lld %lld %lld %lld\n",a[i],b[i],c[i],d[i]);
	}
	printf("%lld\n",c[n]);

} 