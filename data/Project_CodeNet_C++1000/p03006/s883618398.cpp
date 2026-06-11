#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
map<pii,int>pl;
pii pls[54];
int main(void)
{
	int n=0;
	int ans=0,cnt=0;
	int x=0,y=0;
	int i=0,j=0,k=0;
	cin>>n;
	ans=n;
	for(i=1;i<=n;i++)
	{
		cin>>pls[i].first>>pls[i].second;
		pl[pls[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			x=pls[j].first-pls[i].first;
			y=pls[j].second-pls[i].second;
			cnt=0;
			for(k=1;k<=n;k++)
			{
				if(pl.count({pls[k].first+x,pls[k].second+y}))
				{
					cnt++;
				}
			}
			ans=min(ans,n-cnt);
		}
	}
	cout<<ans;
	return 0;
}
