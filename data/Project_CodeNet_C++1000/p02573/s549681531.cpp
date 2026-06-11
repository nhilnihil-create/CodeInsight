#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],f[200005],t[200005];
int find_(int x)
{
	if(f[x]!=x)
	f[x]=find_(f[x]);
	return f[x];
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		int xx=find_(a[i]);
		int yy=find_(b[i]);
		if(xx!=yy)
		f[yy]=xx;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		t[find_(i)]++;
	}
	sort(t+1,t+1+n,cmp);
	cout<<t[1]<<endl;
	return 0;
}