#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)/2)
using namespace std;
int n,ans,a[222222],b[222222],t[888888];
void update(int l,int r,int p,int c,int v){
	if(l==r){t[p]=v;return;}
	mid>=c?update(l,mid,p*2,c,v):update(mid+1,r,p*2+1,c,v);
	t[p]=max(t[p*2],t[p*2+1]);
}
int query(int l,int r,int p){
	if(l==r)return l;
	return t[p]==t[p*2]?query(l,mid,p*2):query(mid+1,r,p*2+1);
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),update(1,n,1,i,b[i]);
	b[0]=b[n],b[n+1]=b[1];
	for(int tmp=n;tmp;){
		int p=query(1,n,1),d=b[p]-a[p],k=b[p+1]+b[p-1];
		if(!d){tmp--,update(1,n,1,p,0);continue;}
		if(d<k){printf("-1");return 0;}
		ans+=d/k,b[p]-=d/k*k,b[0]=b[n],b[n+1]=b[1],update(1,n,1,p,b[p]==a[p]?0:b[p]);
		if(b[p]==a[p])tmp--;
	}
	printf("%lld",ans);
}