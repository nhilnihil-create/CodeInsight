#include<stdio.h>
int main()
{
	int a[100000],n,k,r,s,i;
	while(scanf("%d%d",&n,&k),n)
	{
		for(i=0;i<n;++i)scanf("%d",&a[i]);
		for(s=r=i=0;i<k;++i)s+=a[i];
		for(i=k;i<n;++i)s=s-a[i-k]+a[i],r<s?r=s:0;
		printf("%d\n",r);
	}
}