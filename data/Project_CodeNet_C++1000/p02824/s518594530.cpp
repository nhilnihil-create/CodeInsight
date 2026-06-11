#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define rv(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int M = 120000;
const int inf = 0x3f3f3f3f;
int n,m,v,p;
int a[M];
LL sum[M]={0};
bool exceed=0;
int need;
int cal(int l,int r,int num) {
	if(0==num) return a[r];
	a[r+1]=2*inf;
	int lo=l,hi=r+1;
	LL all=1ll*num*m;
	for(int mid=(lo+hi)>>1;lo<hi;mid=(lo+hi)>>1){
		LL now=all+sum[mid]-sum[l-1];
		LL val=now/(mid-l+1);
		LL ex=now%(mid-l+1);
		LL right=val+!!ex;
		if(right>a[mid+1])
			lo=mid+1;
		else if(right<a[mid])
			hi=mid;
		else {
			if(val>a[l]+m) {
				exceed=1;
				break;
			}
			return max((int)right,a[r]);
		}
	}
	return need;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>v>>p;
	fo(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	fo(i,1,n) {
		sum[i]=sum[i-1]+a[i];
	}
	int ans=p;
	rv(i,n-p,1) {
		int extra = max(0,v-(p-1)-i);
		if(!exceed) need=cal(i+1,n-p+1,extra);
		if(a[i]+m<need) break;
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}
