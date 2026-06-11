#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200050],tag[200050],cnt;
bool vis[200050];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i],a[i]--;
	long long now=0,len=1;
	while(vis[now]!=1)
	{
		vis[now]=1;
		tag[now]=++cnt;
		if(cnt>k)
		{
			cout<<now+1;
			return 0;
		}
		now=a[now];
		len++;
	}
	k-=tag[now];
	k++;
	len=cnt-tag[now]+1;
//	cout<<now<<' '<<len<<' ';
	k%=len;
	for(int i=0;i<k;i++)
	{
		now=a[now];
	}
	cout<<now+1;
	return 0;
}