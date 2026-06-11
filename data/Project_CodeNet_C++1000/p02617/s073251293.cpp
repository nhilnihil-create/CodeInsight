#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;long long ans;
int main()
{
   	scanf("%d",&n);
   	for(int i=1;i<=n;++i)ans+=1ll*i*(n-i+1);
   	for(int i=1,x,y;i<n;++i)
   	{
   		scanf("%d%d",&x,&y);
   		if(x>y)swap(x,y);
   		ans-=1ll*x*(n-y+1);
	}
	printf("%lld\n",ans);
    return 0;
}