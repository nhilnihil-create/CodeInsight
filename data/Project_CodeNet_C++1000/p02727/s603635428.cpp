#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	priority_queue <pair<int,int> > h;
	while(a--)
	{
		int w;
		cin>>w;
		h.push(make_pair(w,1));
	}
	while(b--)
	{
		int w;
		cin>>w;
		h.push(make_pair(w,2));
	}
	while(c--)
	{
		int w;
		cin>>w;
		h.push(make_pair(w,3));
	}
	int z=x+y,ans=0;
	
	while(z)
	{
		pair <int,int> f=h.top();
		h.pop();
		if(f.second==3)
		{
			z--;
			ans+=f.first;
		}
		if(f.second==1 && x)
		{
			z--;
			x--;
			ans+=f.first;
		 } 
		if(f.second==2 && y)
		{
			z--;
			y--;
			ans+=f.first;
		 } 
	}
	cout<<ans;
	return 0;
}