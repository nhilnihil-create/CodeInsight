#include<stdio.h>
int a[100002], b[100002];
int main()
{
	int A, B, m, c, i, minv,temp, mina, minb,x,y;
	while(~scanf("%d %d %d", &A, &B, &m))
	{
		mina=minb=100003;
		for(i=1; i<=A; i++)
		{
			scanf("%d", a+i);
			if(a[i]<mina) mina = a[i];
		}
		for(i=1; i<=B; i++)
		{
			scanf("%d", b+i);
			if(b[i]<minb) minb = b[i];
		}
		minv = mina + minb;
		for(i=1; i<=m; i++)
		{
			scanf("%d %d %d", &x, &y, &c);
			if(minv>(a[x]+b[y]-c))
				minv=(a[x]+b[y]-c);
		}
		printf("%d\n", minv);
	}
	return 0;
}