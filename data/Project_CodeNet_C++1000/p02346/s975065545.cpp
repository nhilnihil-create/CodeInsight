#include<bits/stdc++.h>
#define lowbit(i) ((i)&-(i)) 

using namespace std;

int n,bit[100100];

void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int sum(int x)
{
	int s=0;
	while(x>0)
	{
		s+=bit[x];
		x-=lowbit(x);
	}
	return s;
}

int main()
{
	int q;
	scanf("%d%d",&n,&q);
	memset(bit,0,sizeof(bit));
	for(int i=0;i<q;i++)
	{
		int com,x,y;
		scanf("%d%d%d",&com,&x,&y);
		if(com==0) add(x,y);
		else printf("%d\n",sum(y)-sum(x-1));
	}
	return 0;
}