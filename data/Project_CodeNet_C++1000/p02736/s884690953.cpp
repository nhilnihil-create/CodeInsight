#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005],s,jc[1000005]= {1,1,0,0},ny[1000005]= {1,1,0,0};
int Power(int x,int y,int mod) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int C(int n,int m,int p) {
	if(n<m)return 0;
	return 1ll*jc[n]*ny[m]%p*ny[n-m]%p;
}
int Lucas(int n,int m,int p) {
	if(n<m)return 0;
	if(!n)return 1;
	return 1ll*Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
int main() {
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	int flag=1;
	yyyy:;
	s=0;
	for(int i=1; i<=n; i++)s+=1ll*a[i]*Lucas(n-1,i-1,2);
	if(s%2)return cout<<flag,0;
	int tot=0,cnt[5]= {0};
	for(int i=1; i<=n; i++) {
		b[++tot]=a[i];
	}
	for(int i=1; i<tot; i++)a[i]=abs(b[i]-b[i+1]),cnt[a[i]]++;
	n=tot-1;
	if(cnt[1]||cnt[0]==n)return puts("0"),0;
	for(int i=1; i<tot; i++)a[i]/=2;
	flag=2;
	goto yyyy;
	return 0;
}