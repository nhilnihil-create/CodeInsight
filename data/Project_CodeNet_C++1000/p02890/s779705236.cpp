#include<bits/stdc++.h>
using namespace std;
int sum[3<<17],cnt[3<<17],ans[3<<17],N,i,acc,t,A;
main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A);
		++sum[++cnt[A]];
	}
	i=0;
	for(t=N;t>0;t--)
	{
		while(acc>=i*t)acc+=sum[++i];
		ans[t]=i-1;
	}
	for(i=1;i<=N;i++)printf("%d\n",ans[i]);
}
