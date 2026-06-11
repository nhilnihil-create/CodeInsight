#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1<<13;
const int inf=0x7fffffff/3;
int f[MAXN+50];
int w[1011],num[1010];
int main()
{
	int n,m,b,now=0,c;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>b;
		now=0;
		for(int j=1;j<=b;j++)
		{
			cin>>c;
			now+=(1<<c-1);
		}
		num[i]=now;
	}
	int k=(1<<n)-1;
	for(int i=0;i<=k;i++)  f[i]=inf;
	f[0]=0;
	
	for(int i=0;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i|num[j]]=min(f[i|num[j]],f[i]+w[j]);
		}
	}
	if(f[k]==inf)  f[k]=-1;
	cout<<f[k]<<endl;
	return 0;
}