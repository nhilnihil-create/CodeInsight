#include<iostream>
#include<algorithm>
using namespace std;
int N,M,X;
int c[100000];
struct stu
{
	int a;
	int b[100000];
}book[15];
int main()
{
	scanf("%d%d%d\n",&N,&M,&X);
	int i,j,k;
	int sum,ans=2e9;
	for(i=0;i<N;i++)
	{
		scanf("%d",&book[i].a);
		for(j=0;j<M;j++)
			scanf("%d",&book[i].b[j]);
	}
	for(i=0;i<pow(2,(float)N);i++)
	{
		memset(c,0,sizeof c);
		sum=0;
		for(j=0;j<N;j++)
		{
			if(i>>j&1)
			{
				sum+=book[j].a;
				for(k=0;k<M;k++)
					c[k]+=book[j].b[k];
			}
		}
		bool flag=1;
		for(j=0;j<M;j++)
		if(c[j]<X) flag=0;
		if(flag) ans=min(ans,sum);
	}
	if(ans==2e9) cout<<"-1";
	else cout<<ans;

}