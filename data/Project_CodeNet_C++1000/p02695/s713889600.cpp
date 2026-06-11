#include "bits/stdc++.h"
using namespace std;
 
const int N=200;
 
int n,m,q,arr[N],a[N],b[N],c[N],d[N],ans;
 
void f(int i,int pv)
{
	if(i==n+1)
	{
		int cost=0;
		for(int i=0;i<q;i++)
		{
			if(arr[b[i]]-arr[a[i]]==c[i]) cost+=d[i];
		}
		ans=max(ans,cost);
		return;
	}
	for(int j=pv;j<=m;j++)
	{
		arr[i]=j;
		f(i+1,j);
	}
}
 
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<q;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	f(1,1);
	cout<<ans;
}