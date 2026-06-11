#include<stdio.h>
#include<math.h>
int main()
{
	int n,an=0;
	scanf("%d",&n);
	int a[n],b[n]={},c[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=n;i>0;i--)
		if(a[i-1]!=b[i-1])
		{
			c[an++]=i;
			for(int j=1;j<sqrt(i);j++)
				if(i%j==0)
				{
					b[j-1]=!b[j-1];
					b[i/j-1]=!b[i/j-1];
				}
			int t=sqrt(i);
			if(t*t==i)
				b[t-1]=!b[t-1];
		}
	printf("%d\n",an);
	for(int i=an-1;i>=0;i--)
		printf("%d ",c[i]);
	return 0;
}