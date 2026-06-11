#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	int c;
	int a[15];
}book[15];
int b[15];

int main()
{
//	freopen("input.txt","r",stdin);
	
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<n;i++)
	{
		cin>>book[i].c;
		for(int j=0;j<m;j++) cin>>book[i].a[j];
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<book[i].c<<" ";
//		for(int j=0;j<m;j++) cout<<book[i].a[j];
//		puts("");
//	}
	int ans=-1;
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0;
		memset(b,0,sizeof b); 
		for(int j=0;j<n;j++)
			if((i>>j)&1)
			{
				sum+=book[j].c;
				for(int k=0;k<m;k++) b[k]+=book[j].a[k];
			}
		bool flag=1;
		for(int j=0;j<m;j++) if(b[j]<x) flag=0;
		if(flag)
		{
			if(ans==-1) ans=sum;
			else ans=min(ans,sum);
		}
	}
	cout<<ans<<endl;
	
	return 0;
 } 
 
//每行第一个数前不输出 
 

 
 
 
 
 