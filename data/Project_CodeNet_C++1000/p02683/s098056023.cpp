#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	vector<int>c(n);
	vector<vector<int> >v;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		vector<int>a(m);
		for(int j=0;j<m;j++)cin>>a[j];
		v.push_back(a);
	}
	int ans=1e9;
	for(int mask=1;mask<(1<<n);mask++)
	{
		int cur=0;
		vector<int>b(m,0);
		for(int i=0;i<n;i++)
		{
			if(!(mask&(1<<i)))continue;
			cur+=c[i];
			for(int j=0;j<m;j++)
			{
				b[j]+=v[i][j];
			}
		}
		bool ok=1;
		for(int i=0;i<m;i++)
		{
			if(b[i]<x)ok=0;
		}
		if(ok)ans=min(ans,cur);
	}
	if(ans==1e9)cout<<-1;
	else cout<<ans;
	return 0;
}
