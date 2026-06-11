#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int pri;
	int a[18];
} st[18]; 
const int maxn=1e9;
int b[18];
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<n;i++)
	{
		cin>>st[i].pri;
		for(int j=0;j<m;j++)
		{
			cin>>st[i].a[j];
		}
	}
	int ans=maxn;
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0;
		memset(b,0,sizeof(b));
		int flag=1;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				sum+=st[j].pri;
				for(int k=0;k<m;k++)
				{
					b[k]+=st[j].a[k];
				}
			}
		}
		for(int k=0;k<m;k++)
		{
			if(b[k]<x)
			{
				flag=0;
			}
		}
		if(flag) ans=min(ans,sum);
	}
	if(ans==maxn) cout<<"-1"<<"\n";
	else cout<<ans<<"\n";
	return 0;
}