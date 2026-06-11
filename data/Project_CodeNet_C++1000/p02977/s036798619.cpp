#include<iostream>
#include<cstdio>
using namespace std;
int n;
int vis[100010];
int main()
{
	for(int i=1;i<=100000;i<<=1)vis[i]=1;
	cin>>n;
	if(vis[n])return puts("No")==2333;
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for(int i=4;i<n;i+=2)
	{
		printf("%d %d\n",1,i);printf("%d %d\n",1,i+1);
		printf("%d %d\n",i,n+i+1);printf("%d %d\n",i+1,n+i);
	}
	if(n%2==0)for(int i=2,p;i<=n;++i)
		{
			p=i^1^n;
			if(1<p&&p<n)
			{
				if(i==2)printf("%d %d\n",n,n+i);
				else printf("%d %d\n",n,i);
				printf("%d %d\n",p,n+n);
				break;
			}
		}
	return 0;
}