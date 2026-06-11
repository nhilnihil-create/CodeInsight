#include<bits/stdc++.h>
using namespace std;

long long f[200000],cnt[200000];

long long getf(long long u)
{
	return f[u]==u?u:f[u]=getf(f[u]);
}

void merge(long long u,long long v)
{
	long long f1,f2;
	f1=getf(u),f2=getf(v);
	
	if(f1!=f2)
		f[f2]=f1;
}

signed main()
{
	ios::sync_with_stdio(0);
	
	long long n,m,i,u,v,mx=0;
	cin >>n >> m;
	
	for(i=1; i<=n; i++)
		f[i]=i;
		
	for(i=1; i<=m; i++)
	{ 
		cin >> u >> v;
		merge(u,v);	 
	} 
		
	for(i=1; i<=n; i++)
		cnt[getf(i)]++;
		
	for(i=1; i<=n; i++)
		mx=max(mx,cnt[i]);
		
	cout << mx << endl;
	
	return 0;
}