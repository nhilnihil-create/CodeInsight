#include<stdio.h>
int main()
{
    int n;
    scanf("%lld",&n);
    long long ans=0;
	for(int i=0;i<n;i++)ans=ans+((long long)(n-i)*(long long)(i+1));
    for(int i=1,u,v;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	if(u>v)u=u+v,v=u-v,u=u-v;
    	long long d=(long long)u;
    	if(n-v+1<u)d=(long long)n-v+1;
    	d*=(long long)(n-v+u+1)-d;
    	ans-=(long long)d;
	}
	printf("%lld\n",ans);
    return 0;
}