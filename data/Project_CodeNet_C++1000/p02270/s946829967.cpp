#include<cstdio>
using namespace std;

int w[100000],n,k;
int cntp(int p)
{
	int cnt=1,wgh=0;
	for(int i=0;i<n;)
	{
		if(wgh+w[i]<=p)
		{
			wgh+=w[i++];
		}
		else
		{
			if(wgh>0)cnt++;
			else return k+1; 
			wgh=0;
		}
	}
	return cnt;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;scanf("%d",w+i++));
	int l=0,r=1000000000,m;
	while(l<r)
	{
		m=(l+r)/2;//printf("%d %d %d %d\n",l,m,r,cntp(m));
		if(cntp(m)>k)l=m+1;
		else r=m;
	}
	for(m-=20;;m++)
	{
		//printf("%d %d\n",m,cntp(m));
		if(cntp(m)<=k)break;
	}
	printf("%d\n",m);
	return 0;
}