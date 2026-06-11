#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,K,i,j;
ll a[N],b[N];
int main(){
	scanf("%d%d",&n,&K);
	bool fl=1;
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	for(j=1;j<=K;++j){
		memset(b+1,0,n+1<<3);
		for(i=1;i<=n;++i)++b[max(1ll,i-a[i])],--b[min(n+1ll,i+a[i]+1)];
		for(i=1;i<=n+1;++i)b[i]+=b[i-1];
		memcpy(a+1,b+1,n<<3);
		bool bb=1;for(i=1;i<=n;++i)bb&=a[i]==n;if(bb)break;
	}
	for(i=1;i<=n;++i)printf("%lld%c",a[i],i==n?'\n':' ');
}