#include<bits/stdc++.h>
using namespace std;
vector <pair<long long,long long> > v,v1;
map <pair <long long, long long>, long long > aa;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long i,j,k,a,b,c,x,y,z,n,ans,mn;
	pair <long long, long long> p,p1;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>p.first>>p.second;
		v.push_back(p);
		aa[p]=1;
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (j==i)
			{
				continue;
			}
			p.first=v[i].first-v[j].first;
			p.second=v[i].second-v[j].second;
			v1.push_back(p);
		}
	}
	ans=n;
	for (i=0;i<v1.size();i++)
	{
		mn=n;
		for (j=0;j<n;j++)
		{
			p.first=v[j].first-v1[i].first;
			p.second=v[j].second-v1[i].second;
			if (aa[p]==1)
			{
				mn--;
			}
		}
		ans=min(ans,mn);
	}
	cout<<ans<<endl;
}