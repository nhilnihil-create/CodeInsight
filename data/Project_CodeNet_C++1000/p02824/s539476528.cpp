#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m,v,a[100009];int n,p;
bool check(ll x){
	if(a[n-p+1]>x+m) return 0;
	ll sum=m*v-(p-1)*m;
	for(int i=1;i<=n-p+1;i++){
		ll t=x+m-a[i];
		if(t<=0) break;
		sum-=min(t,m);
		if(sum<=0) return 1;
	}
	if(sum>0) return 0;
	return 1;
}
int main() {
	scanf("%d%lld%lld%d",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(a[mid])) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",n-ans+1);
	return 0;
}