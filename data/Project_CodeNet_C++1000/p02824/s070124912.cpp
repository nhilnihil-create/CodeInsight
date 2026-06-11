#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<time.h>
using namespace std;
typedef long long ll;
int n,m,v,p,a[100005],b[100005],ans,pth_min;
bool judge(int pth){
	ll res=0;
	int i;
	for(i=1;i<=n;i++)
		b[i]=min(m,pth-a[i]);
	sort(b+1,b+n+1);
	if(b[p]<0)
		return 0;
	for(i=1;i<=n;i++)
		res+=i<=p-1?m:b[i];
	return res>=(ll)m*v;
}
int solve(){
	int l=0,r=2e9,mid,res=-1;
	while(l<=r){
		mid=((ll)l+r)>>1;
		if(judge(mid))
			r=mid-1,res=mid;
		else
			l=mid+1;
	}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&v,&p);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	pth_min=solve();
	for(i=1;i<=n;i++)
		ans+=a[i]+m>=pth_min;
	printf("%d\n",ans);
	return 0;
}
