#include <iostream>
using namespace std;
int n,par[200005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
bool Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return 0;
	par[x]=y;
	return 1;
}
void add(int x,int y)
{
	if (Union(x,y))
	printf("%d %d\n",x,y);
}
void one(int x,int y)
{
	add(x,y);
	add(y,1);
	add(1,x+n);
	add(x+n,y+n);
}
void bits(int x)
{
	int l=-1;
	for (int i=0;i<18;i++)
	{
		if (x&(1<<i))
		{
			if (l==-1)
			add(x,(1<<i));
			else
			add((1<<l),(1<<i));
			l=i;
		}
	}
	add((1<<l),x+n);
}
int main()
{
	scanf("%d",&n);
	if (!(n&(n-1)))
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for (int i=1;i<=2*n;i++)
	par[i]=i;
	add(1,2);
	add(2,3);
	add(3,n+1);
	add(n+1,n+2);
	add(n+2,n+3);
	if (n%4==0)
	bits(n);
	if (n%4==1)
	one(n-1,n);
	if (n%4==2)
	{
		add(n-1,1);
		add(n,3);
		add(n-2,n);
		add(2*n-2,n+1);
		add(2*n-1,2*n-2);
		add(2*n,2*n-2);
	}
	for (int i=4;i<=n-3;i+=4)
	{
		add(i,i+1);
		add(i+1,i+2);
		add(i+2,i+3);
		add(i+3,n+i);
		add(n+i,n+i+1);
		add(n+i+1,n+i+2);
		add(n+i+2,n+i+3);
		add(i,i-4+(i==4));
	}
}