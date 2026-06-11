#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mo=998244353;
int n,i,d[N],cnt[N],ans;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",d+i);if(d[1]!=0){puts("0");return 0;}
	sort(d+1,d+n+1);if(n>1 && d[2]==0){puts("0");return 0;}
	for(i=2;i<=n;++i)if(d[i]>d[i-1]+1){puts("0");return 0;}
	for(i=2;i<=n;++i)++cnt[d[i]];
	ans=1;
	for(i=2;i<=d[n];++i)ans=1ll*ans*poww(cnt[i-1],cnt[i])%mo;
	printf("%d\n",ans);
}