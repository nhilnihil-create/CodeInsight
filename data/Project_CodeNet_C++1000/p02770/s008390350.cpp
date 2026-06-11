#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int d[N],t[N],k,q;
ll cal(int n,int x,int m) {
	ll s=0;
	for(int i=0;i<k;i++) {
		t[i]=d[i]%m;
		if(t[i]==0) t[i]=m;
		s+=t[i];
	}
	ll ans=x+s*((n-1)/k);
	for(int i=0;i<(n-1)%k;i++) {
		ans+=t[i];
	}
	return n-1-(ans/m-x/m);
}
int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&k,&q);
	for(int i=0;i<k;i++) {
		scanf("%d",&d[i]);
	}
	for(int i=0,n,x,m;i<q;i++) {
		scanf("%d%d%d",&n,&x,&m);
		printf("%lld\n",cal(n,x,m));
	}
	return 0;
}
