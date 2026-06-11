#include <bits/stdc++.h>
#define LL long long
using namespace std;
int A,B,C,D;
LL ans;
int main()
{
	scanf("%d%d%d%d",&A,&B,&C,&D);
	ans=(LL)A*C;
	ans=max(ans,(LL)A*D);
	ans=max(ans,(LL)B*C);
	ans=max(ans,(LL)B*D);
	printf("%lld\n",ans);
	return 0;
}
