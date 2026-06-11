#include <stdio.h>
#define maxn 5010
#define LL long long
int d[maxn],a[maxn],zero[maxn];
LL sum[maxn];
int main(){
	int k,q,n,x,m,i,ans,t,z;
	scanf("%d%d",&k,&q);
	for(i=0;i<k;i++)scanf("%d",&d[i]);
	while(q--){
		scanf("%d%d%d",&n,&x,&m);
		x%=m,sum[0]=0,zero[0]=0;
		for(i=0;i<k;i++){
			a[i]=d[i]%m;
			sum[i+1]=sum[i]+a[i];
			zero[i+1]=zero[i]+(a[i]==0);
		}
		z=(n-1)/k*zero[k]+zero[(n-1)%k];
		t=((n-1)/k*sum[k]+sum[(n-1)%k]+x)/m-x/m;
		ans=(n-1)-z-t;
		printf("%d\n",ans);
	}
	return 0;
}
