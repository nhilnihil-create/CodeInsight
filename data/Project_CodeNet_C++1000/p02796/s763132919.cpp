#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+100;
struct node {
	int st;
	int ed;
}mac[MAXN];
bool cmp(node a,node b)
{
	return a.ed<b.ed;
}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int pos,len;
		scanf("%d%d",&pos,&len);
		mac[i].st=pos-len;
		mac[i].ed=pos+len;
	}
	sort(mac+1,mac+n+1,cmp);
	int e=mac[1].ed,ans=1;
	for(int i=2;i<=n;i++)
		if(mac[i].st>=e)
		{
			ans++;
			e=mac[i].ed;
		}
	cout<<ans;
}