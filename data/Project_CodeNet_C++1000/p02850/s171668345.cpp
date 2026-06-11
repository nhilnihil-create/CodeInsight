#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
map<pair<int,int>,int> mp;
map<pair<int,int>,bool> mp2,mp3;
vector<int> edge[maxn];
int res[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		--a,--b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		mp[make_pair(a,b)]=mp[make_pair(b,a)]=i;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,(int)edge[i].size());
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		int now=0;
		for(int j=0;j<edge[i].size();j++)
		{
			if(mp3[make_pair(i,edge[i][j])])
			{
				continue;
			}
			if(mp2[make_pair(i,now)])
			{
				now++;
				j--;
				continue;
			}
			res[mp[make_pair(i,edge[i][j])]]=now;
			mp2[make_pair(i,now)]=1;
			mp2[make_pair(edge[i][j],now)]=1;
			mp3[make_pair(i,edge[i][j])]=1;
			mp3[make_pair(edge[i][j],i)]=1;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<res[i]+1<<endl;
	}
	return 0;
}