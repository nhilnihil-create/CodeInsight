#include<stdio.h>
#include<queue>
#include<utility>
#define For(i,a,b) for(register long long i=(a);i<=(b);i++)
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll maxn=2e5+10;
ll n,a[maxn],b[maxn],l[maxn],r[maxn],ans;
priority_queue< pair<ll,ll> > q;
signed main(){
	scanf("%lld",&n);
	For(i,1,n){
		scanf("%lld",&a[i]);
		l[i]=i-1,r[i]=i+1;
	}
	For(i,1,n){
		scanf("%lld",&b[i]);
		q.push(mp(b[i],i));
	}
	l[1]=n,r[n]=1;
	while(!q.empty()){
		int x=q.top().se;
		//printf("%d %d %d\n",x,b[x],a[x]);
		q.pop();
		if(a[x]==b[x]) continue ;
		if(b[x]-b[l[x]]-b[r[x]]<a[x]){
			printf("-1\n");return 0;
		}
		ans+=(b[x]-a[x])/(b[l[x]]+b[r[x]]);
		b[x]=(b[x]-a[x])%(b[l[x]]+b[r[x]])+a[x];
		if(b[x]!=a[x]) q.push(mp(b[x],x));
	}
	printf("%lld\n",ans);
}