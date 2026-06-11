#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+50;
int n,d,A,ans=0,r=1,v[N];
struct node{ int x,z; }a[N];
bool mycmp(node a,node b){ return a.x<b.x; }
int solv(int x){
	if(x%A==0) return x/A;
	else return x/A+1;
}
signed main(){
	scanf("%lld%lld%lld",&n,&d,&A);
	rep(i,1,n) scanf("%lld%lld",&a[i].x,&a[i].z);
	sort(a+1,a+n+1,mycmp);
	rep(i,1,n){
		v[i]+=v[i-1]; a[i].z-=v[i];
		if(a[i].z<=0) continue;
		while(a[r].x-a[i].x<=2*d&&r<=n) r++;
		int t=solv(a[i].z);
		v[i]+=t*A; v[r]-=t*A;
		ans+=t;
	}
	printf("%lld\n",ans);
	return 0;
}