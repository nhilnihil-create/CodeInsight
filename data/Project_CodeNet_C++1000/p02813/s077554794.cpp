#include<bits/stdc++.h>//C - Count Order 
using namespace std;

const int maxn=9;

int n,a,b,c;
int s1[maxn],s2[maxn],s3[maxn];
bool vis[9];

int search(int a[maxn],int b[maxn])
{
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i]) flag=0;
	}
	return flag;
}

void dfs(int u)
{
	if(u>n)
	{
		c++;
		if(search(s1,s3)) a=c;
		if(search(s2,s3)) b=c;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			s3[u]=i;vis[i]=1;
			dfs(u+1);
			s3[u]=0;vis[i]=0;
		}
	}
}

int main()
{
	while(cin>>n)
	{
	 for(int i=1;i<=n;i++)
	  cin>>s1[i];
	 for(int i=1;i<=n;i++)
	  cin>>s2[i];
 	 dfs(1);
	 if(b>a)
	  printf("%d\n",b-a);
	 else printf("%d\n",a-b);
    }
	 return 0;
}