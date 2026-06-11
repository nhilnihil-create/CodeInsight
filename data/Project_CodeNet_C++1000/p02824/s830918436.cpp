#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,m,v,p,a[100005];
bool check(ll x){
	ll y=a[x]+m,z=(v-p+1)*m;
	if(y<a[n-p+1])return false;
	for(int i=1;i<=n-p+1;i++)
		z-=min(m,max(0ll,y-a[i]));
	return z<=0;
}
int main(){
	n=read(),m=read(),v=read(),p=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	ll l=1,r=n-p+1;
	while(l<r){
		ll mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%lld",n-l+1);
	return 0;
}