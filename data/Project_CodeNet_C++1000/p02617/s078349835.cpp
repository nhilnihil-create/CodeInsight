#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
LL ans;
int main(){
	int n,i,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)ans+=(LL)i*(n-i+1);
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		ans-=(LL)u*(n-v+1);
	}
	printf("%lld\n",ans);
	return 0;
}