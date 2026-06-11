#include <cstdio>
const int Maxn=5000;
typedef long long ll;
int d[Maxn+5];
int main(){
	int k,q;
	int n,m,x;
	scanf("%d%d",&k,&q);
	for(int i=1;i<=k;i++){
		scanf("%d",&d[i]);
	}
	ll a;
	int ans;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&n,&x,&m);
		a=(x%m);
		for(int j=1;j<=k;j++){
			a+=1ll*((d[j]+m-1)%m+1)*((n-1+k-j)/k);
		}
		ans=n-1-a/m;
		printf("%d\n",ans);
	}
	return 0;
}
